// mujiang.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��ľ��", ({ "zhang mujiang", "mujiang", "zhang" }));
	set("str", 20);
	set("gender", "����");
	set("age", 43);
	set("long", "���Ǹ����ո߳���ľ����\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/clone/weapon/club",
	}));
	setup();
	setup();
	carry_object("/clone/misc/cloth")->wear();
//	carry_object("/d/city/npc/obj/cloth/male-shoe")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

