 // TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
    set_name("��С��", ({ "sun xiaohong","sun" }) );
        set("gender", "Ů��" );
        set("age", 22);
    set("title", "���ӹ���" );
        set("long",
        "������˵���Ů��,�ִֵı���,�����۾�,�ɰ����ˡ�\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("rank_info/respect", "�ϰ���");
        	set("vendor_goods", ({
                __DIR__"obj/bu1",
                __DIR__"obj/bu2",
                __DIR__"obj/bu3",
                __DIR__"obj/bu4",
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
            say( "��С����˸��򸣣�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��ʲô��\n");
                        break;
           case 1:
            say( "��С���ƺ��������������λ" + RANK_D->query_respect(ob)
                + "�������û������������Ѱ��������Ϣ��\n");
                        break;
                case 2:
            say( "��С�������ʵ�����λ" + RANK_D->query_respect(ob)
                + "����֪��������Ϲٽ��һս������ô��?\n"); 
                        break;
        }
}   
