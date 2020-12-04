// fruit_seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("ˮ������", ({ "fruit seller","seller" }) );
	set("gender", "����" );
	set("age", 28);
	set("long", "һ����ˮ����С���������𾢵������˶���ˮ����\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ({
		__DIR__"obj/apple",
		__DIR__"obj/pear",
		__DIR__"obj/strawberry",
		__DIR__"obj/grape",
		__DIR__"obj/melon",
	}));

	setup();
	add_money("silver", 1);
	add_money("coin", 100);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "ˮ�����Ӹߺ�����ˮ���������������ˮ����\n");
                        break;
                case 1:
                        say( "ˮ�����Ӹߺ����ֽ���ֳ伢����\n");
                        break;
        }
}