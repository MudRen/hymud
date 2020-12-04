// judge.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "judge" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
	set("per", 25);
	set("combat_exp", 11500);
	set("attitude", "friendly");
	set_skill("unarmed", 150);
	set_skill("parry", 170);

	set("inquiry", ([
		"��" : "�͹�����Ǯ���Ҿ����ˡ�\n",
]) );
 
	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom") )
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n�������ⲻ����⵰���ĵط����Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(3) )
	{
		case 0:
			say( CYN"���ٺ������������İɣ���ȫɫ����һ��ˣ���\n"NOR);
			break;
		case 1:
			say( CYN"���ٺ��������ĳ��ţ����߿�����Ǯû�����������\n"NOR);
			break;
		case 2:
			say(CYN"���ٺ������͹������룬����������׿����ȫ��Ӫҵ��\n"NOR);
        }
}
