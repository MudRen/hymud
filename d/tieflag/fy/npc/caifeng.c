 // waiter.c
inherit NPC;
int check_legal_name(string arg);
int check_legal_id(string arg); 
void create()
{
        set_name("老裁缝", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long",
                "这位老裁缝正笑咪咪地忙著，还不时的擦一擦自己的老花眼。\n");
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
 //       add_action("do_ding", "ding"); 
 //       add_action("do_bu", "bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "老裁缝笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来订身衣服吧。\n");
                        break;
                case 1:
                        say( "老裁缝愁眉苦脸说道：这位" + RANK_D->query_respect(ob)
                                + "，你又胖又矮，这帮不了你。\n");
                        break;
        }
} 


