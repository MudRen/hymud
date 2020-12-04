
// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��ͷ��", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "��ͷ����æ���к�����, һ�����Ų��, һ������Ĩ��\n");
	set("combat_exp", 5000);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
//        set("where","north");
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

