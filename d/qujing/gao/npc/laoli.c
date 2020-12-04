// laoli.c

inherit NPC; 

void create()
{
        ("lao_li");
        set_name("����ͷ", ({"lao li", "li"}));
        set("long", "���̵����ˣ�\n");
        set("gender", "����");
        set("title", "����");
        set("per", 15);
        set("combat_exp", 6800);
        set("age", 56);
        set("attitude", "friendly");
        set("shen_type", 1);
        set_skill("unarmed", 15);
        set("chat_chance", 5);
        set("chat_msg", ({
                name()+"һ������Сѧͽ��ƨ���ϣ��µ�������͵����\n",
                name()+"��Сѧͽ�µ���������ٴ��ˣ�����ô��ô����\n",
        }) );
        set("vendor_goods", ({
                "/d/qujing/gao/obj/blade",
                "/d/qujing/gao/obj/sword",
                
        }));
        setup();
        add_money("coin", 50+random(200));
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"����˵������λ" +
RANK_D->query_respect(ob)
                                + "��Ҫ��������\n");
                        break;
        }
}

