// caifeng_boss.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���ɩ", ({ "boss li", "boss","li" }) );
	set("gender", "Ů��" );
	set("title","�÷����ϰ�");
        set("age", 35);
	set("per",20);
        set("long","����һλ��ʵ��ɽ���ɩ��\n");
        set("combat_exp", 10000);
set("vendor_goods", ({
		"/d/city/npc/cloth/belt",
		"/d/city/npc/cloth/boots",
		"/d/city/npc/cloth/bu-shoes",
		"/d/city/npc/cloth/cloth",
		"/d/city/npc/cloth/color-dress",
		"/d/city/npc/cloth/fu-cloth",
		"/d/city/npc/cloth/gui-dress",
		"/d/city/npc/cloth/hat",
		"/d/city/npc/cloth/jade-belt",
		"/d/city/npc/cloth/liu-dress",
		"/d/city/npc/cloth/marry-dress",
		"/d/city/npc/cloth/mini-dress",
		"/d/city/npc/cloth/moon-dress",
		"/d/city/npc/cloth/pink-dress",
		"/d/city/npc/cloth/qi-dress",
		"/d/city/npc/cloth/red-dress",
		"/d/city/npc/cloth/scarf",
		"/d/city/npc/cloth/sha-dress",
		"/d/city/npc/cloth/xian-cloth",
		"/d/city/npc/cloth/xiu-cloth",
		"/d/city/npc/cloth/xiu-scarf",
		"/d/city/npc/cloth/yan-dress",
		"/d/city/npc/cloth/zi-dress",
	}));
        set("attitude", "friendly");

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
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

	say( "���ɩ΢Ц�š�\n");

}
