//Edited by fandog, 02/13/2000
#include <ansi.h>
inherit NPC;
int ask_yuan();
int ask_kong();
void create ()
{
	set_name("�ݷ�", ({"qi fang","qi"}));
	set("long", "һλ��ɫ�������ٸ���ԲԲ��������һ˫���ۺ�����ģ����ϲ�ʩ֬�ۣ���ɫ��Ϊ�㲡�\n");
	set("gender", "Ů��");
	set("age", 20);
	set("combat_exp", 1000000);
	set("str", 20);
	set("int", 28);
	set("dex", 23);
	set("con", 26);
	set("per", 26);
	set("kar", 26);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("feixian-steps", 60);
	set_skill("liancheng-jian", 360);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
          
          	set_temp("apply/attack", 118);
	set_temp("apply/defense", 112);
	set_temp("apply/damage", 711);
	set_temp("apply/armor", 777);
          set("inquiry", ([
            "����" : (: ask_yuan :),
            "���Ĳ�" : (: ask_kong :),
        ]) );	
         set("chat_chance", 10);
         set("chat_msg", ({
		"�ݷ���Ц���������˵���������Ĳˣ���㵽�Ķ������赽���Ҳ��š���\n",
		"�ݷ���Ц�Žе��������Ĳˣ��㻹����������\n",		
	}));   
	setup();
	carry_object("/clone/cloth/female1-cloth")->wear();
}


int ask_yuan()
{
	object me = this_player();
        command("consider");
        command("say ����Ϥ�ĵط�����������ɹ�ȳ��ϣ��һ���һ�����ӱ��Թ��书�ġ�\n");
        command("?");
        me->set_temp("yuan",1);
        return 1;
}

int ask_kong()
{
	object me = this_player();
	object ob;
if (this_object()->query("get") ) return 0;
	{
		message_vision(CYN"�ݷ�Ц�������Ѿ���������!\n"NOR,me);
		return 1;
	}

	if(me->query_temp("yuan")!=1)
	{
		message_vision(CYN"�ݷ�Ц�����������ҵ�Ů����\n"NOR,me);
		return 1;
	}
	else
	{
		message_vision(CYN"�ݷ���˼��һ������ó���һ����ݸ���$N��\n"NOR,me);	
		ob = new ("/d/jingzhou/obj/tangshixuan");
		ob->move(me);
this_object()->set("get",1);
		me->delete_temp("yuan");
		return 1;
	}
}	