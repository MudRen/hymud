// ywaiter.c

inherit NPC;

void create()
{
        set_name("С���", ({ "waiter" }) );
        set("title", "����ҩ��");
        set("gender", "����" );
        set("age", 17);
        set("long", "����ҩ�̵�С��ƣ���ѧ����ҩ��\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 30);
        set_skill("parry", 10);
        set_skill("dodge", 10);

        set("inquiry", ([
                "ץҩ" : "���������ҩ��ã���Ҫ��ʲô��",
        ]) );

       setup();
        add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "С��Ƴ��˼�ζҩ��������ֽ����\n");
                        break;
                case 1:
                        say( "���΢Ц��˵������λ"  
                                + RANK_D->query_respect(ob)
                                + "����ҩ��\n");
                        break;
        }
}
