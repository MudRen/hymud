 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("С����", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("cor",12);
        set("long",
                "һ������С���ӵ�����С��\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
	set("vendor_goods", ({

                __DIR__"obj/sandals",
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
        switch( random(3) ) {
                case 0:
            say( "С����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "����ɽ�ģ�\n");
                        break;
           case 1:
            say( "С��������Ĩ��Ĩͷ�ϵĺ���˵������λ" + RANK_D->query_respect(ob)
                                + "��ɽ�ϵĶ����ܹ���ϣ�\n");
                        break;
                case 2:
            say( "С����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ֱ����ֺã�\n");
                        break;
        }
} 
