 // worker.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("��������", ({ "flower seller", "seller" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("per", 40);
        set("long", "�������������������������ۻ���\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 25);
        set_skill("dodge", 150);
        set_skill("throwing", 100); 
        set("inquiry", ([
                "С��" : "��Ҫ������ɽȥ�ʡ�", 
        ]) );
        set("chat_chance", 5);
        set("chat_msg", ({
                (:random_move :)
        }) );

        
	set("vendor_goods", ({
                __DIR__"obj/purple_flower",
                __DIR__"obj/red_flower",
                __DIR__"obj/yellow_flower",
                __DIR__"obj/blue_flower",
                __DIR__"obj/white_flower",
                __DIR__"obj/black_flower",
	}));        
        setup();
        add_money("coin", 15);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/flower")->wield();
        carry_object(__DIR__"obj/flower")->wield();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) {
                case 0:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������ĵ���� \n");
                        break;
                case 1:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������ö���� \n");
                        break;
                case 2:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����ײ軨�� \n");
                        break;
                case 3:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������������� \n");
                        break;
                case 4:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������ö���� \n");
                        break;
                case 5:
                        say( " ��������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������ö���� \n");
                        break; 
        }
}    
