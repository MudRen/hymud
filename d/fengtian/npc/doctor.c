// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����", ({"doctor hu"}));
	set("long", @TEXT
������ҽ����ʢ��С��������
TEXT
        );
	set("gender","����");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);
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