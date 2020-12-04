// jishi.c


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "wang jishi","wang" }) );
        set("title", "ҩ���ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "������ҩ�̵��ϰ���������һλ�Һ��ߡ�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
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
        set("inquiry", ([
                "ץҩ" : "�����Ǹ�����õ�ҩ�꣬��Ҫʲô��",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}