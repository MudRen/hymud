//Writen by lnwm (May.28.1997)
//woman.c

inherit NPC;

void create()
{
        set_name("妇人", ({ "fu ren","woman" }) );
        set("gender", "女性" );
        set("age", 35);
        set("long",
"一个典型的四川乡下女人，总是看起来忙忙碌碌的。\n"
        );
        set("combat_exp", 1000);

        set("inquiry", ([
        "孩子"          : "我有一个男孩和一个女孩",     
        "男孩"          : "就我那小子淘气，你看，到现在还没有回来",
        ]) );

        set("chat_chance", 10);
        set("chat_msg",({                             
"女人放下手里的活，看了看外面说：我那个小子怎么还不回来。\n",
"女人放下手里的活，看了看外面，转头对丈夫说：你也不出去找找。\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
            remove_call_out("greeting");
            call_out("greeting", 2, ob);
        }
}                            

void greeting(object ob)
{
    object obj;
    if( !ob || environment(ob)!= environment(this_object()) )
        return;
        write("\n女人看见你进来，笑了笑，说:'随便坐'.\n");
        write("\n女人说：请尝尝我们自己产的茶叶。\n");
/*
    if( objectp(present("hua cha",ob) ) && !me->query_temp("marks/lnwm/花�")�)
    {
        write("\n女人递给你一杯清茶。\n");
        obj = new( __DIR__ "obj/tea");
            obj -> move(ob);
        
    }
*/
}                                                     




