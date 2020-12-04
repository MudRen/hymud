// ma-fanzi.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({"ma fanzi"}));
	set("long", @TEXT
һ����ͷ���ֵ���������
������������������
TEXT
        );
	set("gender","����");
	set("age",35);
	set("con",20);
	set("str",20);
	set("combat_exp",200);


	setup();
	carry_object("/clone/misc/cloth")->wear();
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
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n��������⵰��������ʲô���Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(2) )
	{
		case 0:
			say( CYN"����Ц�����˵������λ�͹�ѡһƥ����ɡ�\n"NOR);
			break;
		case 1:
			say( CYN"���ӵ�ͷ����˵������λ" + RANK_D->query_respect(ob)
			+ "�����������½��ļ�ƥ���\n"NOR);
			break;
	}
}
