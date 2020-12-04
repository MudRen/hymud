 // Tie@fy
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("沙罗门", ({ "shaluomen" }) );
        set("gender", "男性" );
        set("age", 62);
        set("long","沙罗门来自天竺，生性寡僻，专门与动物为伍，擅长驯兽（ｔｒａｉｎ）。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );
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
 //       add_action("do_train", "train"); 
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "沙罗门说道：这位" + RANK_D->query_respect(ob)
                                + "，回天竺怎么走？\n");
                        break;
                case 1:
                        say( "沙罗门叹道：这位" + RANK_D->query_respect(ob)
                                + "，我帮你驯兽，你指点一下我回家的路吧。\n");
                        break;
        }
} 
