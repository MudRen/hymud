#include <ansi.h>
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg); 
void create()
{
        set_name("张铁匠", ({ "zhang" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long","张铁匠一身打铁功夫名不虚传，他打出的铁器经久耐用．\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
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
//    add_action("do_ding", "ding");
//        add_action("do_xiu", "xiu");
}  
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "张铁匠粗声粗气地说道：这位" + RANK_D->query_respect(ob)
                                + "，要什么？\n");
                        break;
                case 1:
                        say( "张铁匠满脸汗水说道：这位" + RANK_D->query_respect(ob)
                                + "，我太忙了，帮不了你。\n");
                        break;
        }
} 
