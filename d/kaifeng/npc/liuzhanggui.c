inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���ƹ�", ({ "liu zhanggui", "liu", "zhanggui" }) );
        set("gender", "����" );
        set("age", 25);
        set("title", "�������ϰ�");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 130);

        set("vendor_goods", ({
                __DIR__"obj/ciwan",
                __DIR__"obj/luowenhai",
                __DIR__"obj/bibohu",
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{       
        object ob; 

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        ::init();
}
