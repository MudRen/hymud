//Writen by lnwm
//kanzhu.c

inherit NPC;

void create()
{
        set_name("砍竹人", ({ "kanzhu ren","ren" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
"一位正在忙忙碌碌砍竹子的中年农夫，手里拿一吧柴刀。\n"
        );
        set("combat_exp", 5000);

        set("inquiry", ([
        "竹子"          : "这竹子是用来卖到山下去的",     
        ]) );

        set("chat_chance", 1);
        set("chat_msg",({                             
"砍竹人把砍下的竹子扎成一捆。\n",
"砍竹人擦擦脸上的汗，自言自语道：明天就背下山去卖。\n",
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/chaidao")->wield();
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
    if( !ob || environment(ob) != environment( this_object() ) )
        return;

        write("\n砍竹人看见有人走过来，回了一下头，又接着忙手里的活。\n");
}                                                     




