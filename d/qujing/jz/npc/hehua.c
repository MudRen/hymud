//Cracked by Roath

inherit NPC;inherit F_DEALER;
void create()
{
        
        set_name("�ɻ�", ({"he hua", "hua"}));
        set("title", "������");
        set("gender", "Ů��");
        set("age", 19);
        set("long", "һ����Ư����С�����������������䡣\n");
        set("per",30);
        set("combat_exp", 20000);
	set("combat_exp",20000);		
        set("vendor_goods", ({
               "/d/qujing/jz/obj/lan",
                "/d/qujing/jz/obj/mei",
                "/d/qujing/jz/obj/mudan",
               "/d/qujing/jz/obj/purple",
        }));
        setup();
   add_money("silver", 5);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                      say( name()+"Ц������仨��������˰ɣ�\n");
                        break;
        }
}
