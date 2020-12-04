 // tea_waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("��С��", ({ "wan xiaochun","wan" }) );
        set("gender", "����" );
        set("title", "��ѧ����" );
        set("age", 23);
        set("long",
                "һ����ü��������ͷɥ���ļһ�Գ�����ҽ������Զ����ֶ��\n����������͵��Щ�鵤��Ǯ����\n");
       set("combat_exp", 200000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��С����������������������˵����㰡�����������ؼҵ��̲���û�ˣ�\n�������������кðɡ���\n",
                "��С��������һ�ۣ����������������Һ��һ�����Щ�����常��\n��͵�����鵤��ҩ���ɶ�����ҽ�����ı�����\n",
                "��С��һƨ�����ڵ��ϣ�һ�����ذ���̾����\n", 
        }) ); 
        set("attitude", "friendly");
	set("vendor_goods", ({
                __DIR__"obj/senyao",
                __DIR__"obj/keeyao",
                __DIR__"obj/ginyao",
	}));
        setup(); 
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
        switch( random(2) ) {
                case 0:
                        say( "��С��������������λ" + RANK_D->query_respect(ob)
                                + "������ͷ��Щ�鵤��ҩ�ɶ����޼�֮����Ҫ��\n����ȫ��ҵ�����λ����㡣����\n");
                        break;
                case 2:
                        say( "��С������˵������λ" + RANK_D->query_respect(ob)
                                + "������˵������¾����⻹���⼸��ҩ���ߣ�����ͷ��\n�ϴ��������գ��ҾͰ����ı����䷽ȫ���ˡ���\n");
                        break;
        }
}         
