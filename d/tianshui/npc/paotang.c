// paotang.c


inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "waiter" }) );
	set("title","���ɸ�");
        set("gender", "����" );
        set("age", 22);
        set("long","С��������æ�ţ�����ʱҪ�ͽ����Ŀ��˴��к���\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/noodles",
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));        
        setup();
}

void init()
{       
        object ob;

        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");        	        	
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
                        say( "С����Ц�����˵�������ɸ�ķ���Զ��������\n");
                        break;
                case 1:
                        say( "С����һ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}
