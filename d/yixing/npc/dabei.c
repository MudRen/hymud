// /d/yixing/npc/dabei.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;
int ask_me();
void create()
{
	set_name("������", ({"dabei laoren", "dabei" }));
	set("long", "���Ǹ��������ߣ��׷����أ�������ΰ��\n");
	set("title", "�׾�����");
	set("gender", "����");
	set("attitude", "friendly");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("parry", 120);
	set_skill("qianye-shou", 120);
	set_skill("longzhua-gong", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");
        set("inquiry", ([

"ʯ����" : (: ask_me :),
        ]));
	setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/book/18niou");
}


int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book91121"))
	{
		message_vision("$N��$n˵���� �ұ��ض��Ĵ���������׷ɱ�����ڰﲻ���㡣\n",this_object(),who);
  
		return 1;	
	}
	if(!who->query_temp("book91122"))
	{
		message_vision("$N��$n˵���� �ұ��ض��Ĵ���������׷ɱ�����ڰﲻ���㡣\n",this_object(),who);
  
		return 1;	
	}
	if(!who->query_temp("book91123"))
	{
		message_vision("$N��$n˵���� �ұ��ض��Ĵ���������׷ɱ�����ڰﲻ���㡣\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book91124"))
	{
		message_vision("$N��$n˵���� �ұ��ض��Ĵ���������׷ɱ�����ڰﲻ���㡣\n",this_object(),who);
  
		return 1;	
	}	
	

	  	if(((int)who->query("jinyong/book11")>=2))
	{
		message_vision("$N��$n˵���� ��л��ȣ�\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮������\n",this_object(),who);
	message_vision("$N��$n˵���� �ҿ���ʯ�����л�̿�ץ��Ħ����ȥ�ˡ���\n",this_object(),who);
if(who->query("jinyong/book11")==1)	
{
        i = 500+random(800);
	who->set("jinyong/book11",2);
	who->add("combat_exp",i+12880);
	who->add("potential",i*15);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+12880)+"�㾭��"+
	           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ�ڸ���......\n"NOR,ob);
destruct(this_object());
   return;      
}