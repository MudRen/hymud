inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("�����ӵ�", ({ "dumpling seller", "seller" }) );
        set("gender", "����" );
        set("age", 33);
        set("per", 18);
        set("long", "��������ӵ�С������΢΢һЦ��˵���������ڵİ��ӣ���һ���ɣ�\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
	}));
//        set("chat_chance", );
        set("chat_msg", ({
                "�����ӵ�ߺ�ȵ������ӣ������ڵİ��ӣ�\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

