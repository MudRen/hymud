// girl.c
#include <ansi.h>
inherit NPC;



void create()
{
	set_name(BLU"����"NOR, ({ "ah xiang","xiang"}));
        set("gender", "Ů��" );
        set("title","����С����");
	set("age", 15);
	set("long",
		"һ��Ư���ɰ��İ���С���\n");
	set("combat_exp", 600+random(400));
        set("social_exp", 600+random(400));
	set("attitude", "friendly");
        set_temp("apply/attack",20+random(100) );
        set_temp("apply/defense",20+random(100) );
        set_temp("apply/damage",random(5) );
        set_temp("apply/armor",random(5) );
	setup();
       	carry_object(__DIR__"obj/cloth2")->wear();
	add_money("coin", 10);
	set("score",5);
}

