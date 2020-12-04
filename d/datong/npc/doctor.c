// doctor.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�Ӽ���", ({ "zhong jishi" }) );

        set("gender", "����" );

        set("age", 38);

	set("long", "�Ӽ����Ǵ�ͬ��Զ����������ҽ��\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));
        setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
 
}