//Cracked by Kafei

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "nei shi", "shi" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"���Ǹ����ҵ��̴ӡ�\n");
	set("combat_exp", 1000);
        set("shen_type", 0);
	set("attitude", "peaceful");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 3400);
	set("eff_qi", 3400);
	set("qi", 3400);
	set("max_jing", 3500);
	set("jing", 3500);

	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);

	setup();

        carry_object("/d/city/obj/cloth")->wear();
}

