 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("����", ({ "afa" }) );
    set("title", "С³��");
        set("gender", "����" );
        set("age", 35);
        set("long",
                "����ܰ����㿴���尢��������\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                "/d/resort/obj/bblade",
        "/d/resort/obj/bsword",
        }));
        set_skill("unarmed",5);
        setup();
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
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N��$n˵�����֪��֪������Ϭ������������Ī�ö�����ľ����Ļ�������\n",this_object(),ob);
                        break;
        }
}   
