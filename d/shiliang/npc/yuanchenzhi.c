// Feb. 6, 1999 by Winder
// jinshe.c �����ɾ�
#include <ansi.h>
inherit NPC;

void dest(object ob);
int ask_me();
int ask_me2();
void create()
{
	set_name("Ԭ��־", ({"yuan chenzhi", "yuan", "chenzhi"}));
	set("nickname", HIY"��ʡ��������"NOR);
	set("gender", "����");
	set("age", 25);
       set("long", "
������Ԭ������ӡ�����Ե�ɺ��¸����˻�ɽ����������Գ������Ϊʦ��\n ���������ŵ�ǧ�����ľɣ���˺ͽ����ɾ���ѩ�˵Ľ�������ѧ��һ�����书��\n��ɽ�����������壬��ʶ��ѩ��֮Ů������ͳ�ƽ�������š���ʮ������Ϊ��ʡ����������\n");

 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 30);
	set("con", 30);
	set("dex", 135);

	set("inquiry", ([
		"Ӫ��" : (: ask_me :),
		"����" : (: ask_me2 :),
		"�ȹ�" : (: ask_me2 :),
	]));
	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 9000000);
	set_skill("jinshe-zhang",380);
	set_skill("force", 300);		// �����ڹ�
	set_skill("huntian-qigong", 300);	// ��������
	set_skill("unarmed", 320);		// ����ȭ��
	set_skill("dodge", 300);		// ��������
	set_skill("strike", 300);
	set_skill("parry", 300);		// �����м�
        set_skill("sword", 300);                // ��������
        set_skill("jinshe-jian",400);           // ���߽���
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
	map_skill("strike", "jinshe-zhang");
        prepare_skill("strike", "jinshe-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),                
                (: perform_action, "sword.kun" :),                
                (: perform_action, "sword.shi" :),                
                (: perform_action, "sword.suo" :),                
                (: perform_action, "sword.wan" :),                
                (: perform_action, "strike.fugu" :),  
        }) );
	set_temp("apply/attack",  250);
	set_temp("apply/defense", 250);        	
	set_temp("apply/damage", 2250);   
	set_temp("apply/armor", 2250);   
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book13")>=3))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��λ�ֵܡ���\n",this_object(),who);
	message_vision("$N��$n˵���� ����Ҫȥ��ɽɱ���Ƕ��������ӣ��ֵ��������ˡ�\n",this_object(),who);
if((int)who->query("jinyong/book13")==2)
{
	i = 800+random(1800);
	who->set("jinyong/book13",3);
	who->add("combat_exp",i+12880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+12880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	
	
}


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


int ask_me2()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book13")>=4))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� �ҵ�֪ ��̫��ܻ�����ϵ�� ����ʵۻ�̫�� ����ı��\n",this_object(),who);
	message_vision("$N��$n˵���� ��ҲҪȥ��������£� ���ȿ���һ������书�ɡ�\n",this_object(),who);
who->set_temp("book1342",1);
kill_ob(who);
	return 1;
}


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

                if ((int)who->query("jinyong/book13")==3)
{
                i = 500+random(2000);
		who->set("jinyong/book13",4);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		//message("channel:chat", HIB"������III����˵"+who->name() + "�����Ц����������������!"NOR"\n", users());
		message_vision("$N��$n˵���� ����书������������ʢ���ʹ����档\n",this_object(),who);
		who->save();
}		
		
	call_out("destroying", 0);

}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    