// cha_sell.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ɩ", ({ "ma dasao" }) );
	set("title","����ϰ���");
        set("gender", "Ů��" );
        set("age", 35);
        set("long","����һλ����Ц�ݵ����긾Ů��\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

	set("sell_all_day",1);

        setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob;

	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}