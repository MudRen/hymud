// yaoboss.c
// by dicky

inherit NPC;
inherit F_DEALER;


void create()
{
        set_name("�ż���", ({ "zhang jishi","boss","jishi"}) );
        set("title", "ҩ���ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "������ҩ�̵��Ű���������һλ�Һ����ߡ�\n");

       	set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set("sell_all_day",1);

        set("inquiry", ([
                "ץҩ" : "�����Ǹ�����õ�ҩ�꣬��Ҫʲô��",
        ]) );

	set("vendor_goods", ({
		__DIR__"obj/yao",
		__DIR__"obj/xuelian",
	}));


        setup();
        add_money("silver", 10);
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
