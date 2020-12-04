 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("�ӻ����ϰ�", ({ "seller" }) );
        set("gender", "����" );
        set("age", 34);
        set("long",
                "��λ�ӻ����ϰ������ڹ�̨�������ʣ���ʱ��̧ͷ��һ�����⡣\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
		"/d/city/npc/obj/sniurou",
		"/d/city/npc/obj/sjiudai",
	//"/clone/misc/newpaper",
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
                        say( "�ӻ����ϰ�Ц������ʵ�����λ" + RANK_D->query_respect(ob)
                                + "����Ҫ���ʲô��\n");
                        break;
                case 1:
                        message_vision("$N���ڵ�ͷ���ʣ���ûע�⵽$n������\n", this_object(), ob);
                        break;
   }
} 

