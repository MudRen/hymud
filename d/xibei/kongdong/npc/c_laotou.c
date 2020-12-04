inherit NPC;


void create()
{
        set_name("挑菜老头", ({ "tiaocai laotou","laotou" }) );
        set("gender", "男性" );
        set("age",60);
        set("inquiry", ([
                "路" : "一直沿着石阶上到尽头就是了。\n",
                        ]) );
        set("social_exp",2000);
        set("combat_exp",10000);
        set("force",200);
        set("max_force",200);
        set("force_factor",10);

        setup();
        carry_object(__DIR__"obj/linen")->wear();
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player()) && !is_fighting()){
            remove_call_out("greeting");
            call_out("greeting",1,ob);
            }
}

void greeting(object ob)
{
        if(!ob||!present(ob,environment(this_object())))return;
        say("挑菜老头对你郑重其事地说："+RANK_D->query_respect(ob)
            +"，听说这崆峒山上可有神仙呀。\n");
        }
