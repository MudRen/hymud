// /d/tianshui/npc/tea boss.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��ʦ", ({ "tea boss","boss" }) );
        set("gender", "����" );
        set("age", 39);
        set("long","��ʦ��������һ�������������æ�ţ�����ʱ�Ϳ��˴��к���\n");
        set("combat_exp", 200);
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

	
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"��ʦЦ�����˵������ӭ���٣�С����������ȫ����������\n"NOR);
                        break;
                case 1:
                        say( CYN"��ʦһ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
		}
	}
}