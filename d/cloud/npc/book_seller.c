
// seller.c
// By L.G.

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�����", ({ "seller" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "������Ǹ�����С���ӣ����΢Ц��\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set("vendor_goods", ({
                "/d/city/npc/obj/lbook1",
                "/d/city/npc/obj/lbook2",
                "/d/city/npc/obj/lbook3"
        }));


//        set("where","north");
        setup();
//        add_money("gold", 1);
        add_money("coin", 300);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_list","list");
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
                        say( "�����Ц����ӭ��������λ"
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��ʲô��\n");
                        break;
                case 1:
                        say( "�������æ���������\n");
                        break;
        }
}

