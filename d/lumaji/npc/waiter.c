// waiter.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 20);
	set("str",50);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	if( interactive(ob = previous_object()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n˵������⵰Ҳ��ס�꣬�Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(2) )
	{
	case 0:
		say( CYN"��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
			+ "�������ȱ��裬ЪЪ�Ȱɡ�\n"NOR);
		break;
	case 1:
		say( CYN"��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
			+ "����������\n"NOR);
		break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 500)
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		return 1;
	}

	else
	{
		tell_object(who, "С��ҡҡͷ˵����ס��һ���������ӡ�\n");
			return 0;
	}
}
