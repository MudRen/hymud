// smith.c
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("������", ({ "smith zhang","zhang","smith" }) );
        set("gender", "����" );
        set("age", 38);
	set("str",88);
        set("long", "������ѩͤ�����������ϰ���������\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));

        setup();

	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
