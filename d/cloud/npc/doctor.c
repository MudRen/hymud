
// doctor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���", ({ "waiter" }) );
        set("title", "ҩ��");
        set("gender", "����" );
        set("age", 17);
        set("long", "ҩ���С��ƣ�����ѧ����ҩ��\n");
        set("combat_exp", 100);
        set("attitude", "heroism");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);
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

//        set("where","north");
 

	setup();
	add_money("coin", 50);
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
        switch( random(4) ) {
                case 0:
                        say( "С��Ƴ��˼�ζҩ��������ֽ����\n");
                        break;
                case 1:
                        say( "��Ƶ�ͷ������λ"  
				+ RANK_D->query_respect(ob)
                                + "����ҩ��\n");
                        break;
        }
}

