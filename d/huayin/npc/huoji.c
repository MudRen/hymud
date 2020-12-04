// paotang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("С���", ({ "huo ji" }) );
        set("gender", "����" );
        set("age", 22);
        set("long","С�������æ�ţ�����ʱҪ�ͽ���
�Ŀ��˴��к���\n");

	set("sell_all_day",1);
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
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	::init();
        if( living(ob = previous_object()) && random(2) && !is_fighting() && !wizardp(ob))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	say( CYN"С����һ����˵������λ" + RANK_D->query_respect(ob)
		+ "����������\n"NOR);
}