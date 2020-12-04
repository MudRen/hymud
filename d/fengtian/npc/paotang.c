// paotang.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��¥����", ({ "pao tang","waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long","��������æ�ţ�����ʱҪ�ͽ����Ŀ��˴��к���\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");		
        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n�������ⲻ�������ĵط����Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(1==2)
	{
		
		say( (time > 480) ? CYN"��ô����죬С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"С���õ�ͷ���������Ͼ�Ҫ�����ˣ���λ�͹����һ�°ɡ�\n"NOR
			: CYN"���ô��˸�����˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 1:
			say( CYN"����һ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
		}
	}
}
