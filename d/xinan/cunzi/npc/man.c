//Writen by lnwm (May.28.1997)
//man.c

inherit NPC;

void create()
{
        set_name("男人", ({ "nan ren","man","ren" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
"一个典型的四川农夫，身体健壮，看起来朴实憨厚。\n"
        );
        set("combat_exp", 3000);

        set("inquiry", ([
        "孩子"          : "我有一个男孩和一个女孩",     
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({                             
"男人拾掇着手里的农具。\n",
"男人转过头对妻子说：让他在外边玩呗，男孩嘛.\n",
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
                call_out("greeting", 1, ob);
        }
}                            

void greeting(object ob)
{
        if( !ob || environment(ob) != environment(this_object()))
             return;
        write("\n男人看见你进来，冲你点了一下头，又接着忙手里的活。\n");
}                                                     




