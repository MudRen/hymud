// zhao.c
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	set_name("�԰�ɽ", ({"zhao banshan", "zhao", "banshan"}));
	set("title", HIR"�컨��"HIG"������"NOR);
	set("nickname", HIY "ǧ������" NOR );
	set("gender", "����");
	set("age", 48);
	set("long", 
"��һ�����ֵ�����Ц��������һ���ܴ���ĸо�����
ԭ����������̫�������Ŵ���ӡ�������������
����һ�ְ��������̫����������ƥ�С����������
��ɢ֮��Ͷ��컨�ᡣ�ܵñ��컨���ϵ�������ͤ
��ʶ��\n");
	set("attitude", "peaceful");
	set("class", "fighter");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 7500);
	set("max_qi", 7500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 12500);
	set("max_neili", 12500);
	set("jiali", 100);
	set("combat_exp", 1000000);

	set_skill("force", 190);
	set_skill("taiji-shengong", 190);
	set_skill("unarmed", 190);
	set_skill("taiji-quan", 190);
	set_skill("throwing", 200);
	set_skill("hanxing-bada", 190);
	set_skill("dodge", 190);
	set_skill("tiyunzong", 190);
	set_skill("mantian-xing", 290);
	set_skill("parry", 190);
	set_skill("sword", 190);
	set_skill("taiji-jian", 190);

	map_skill("force"  , "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("dodge"  , "tiyunzong");
	map_skill("parry"  , "taiji-jian");
	map_skill("sword"  , "taiji-jian");
	map_skill("throwing"  , "hanxing-bada");

	        set("inquiry", ([
                "�����̼�" : (: ask_me :),
        ]) );
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: command("wield changjian") :),
		(: command("haha") :),
		(: command("unwield changjian") :),
		(: command("wield jili") :),
		(: command("unwield jili") :),
	}));
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/jili")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
  	if(((int)who->query("combat_exp",1)<=1000000))
	{
		message_vision("$N��$n˵���� ����书̫���ˣ����书�õ������ɣ�\n",this_object(),who);
		return 1;	
	}	

	  	if(((int)who->query("jinyong/book1")>=1))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮����\n",this_object(),who);
	message_vision("��˵��ɽ������һ������ �������������\n",this_object());
	message_vision("�����Ҳ�Ǹ����ţ����������˴�� ��һ��Ҫȥ��ʶһ�¡�\n",this_object());

	
	i = random(800);
	who->set("jinyong/book1",1);
	who->add("combat_exp",i+6880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+6880)+"�㾭��"+
	           chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}