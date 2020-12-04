//writen by lnwm
//girl.c

inherit NPC;

void do_smile();
void create()
{
        set_name("小姑娘", ({ "little girl","girl" }) );
        set("gender", "女性" );
        set("age", 16);
        set("long",
          "一个千娇百媚的小姑娘，穿着一身红红的衣衫
冲你甜甜地笑着\n"
        );
        set("combat_exp", 1000);

        set("chat_chance",10);
        set("chat_msg",({
"小姑娘说：你好\n",
"小姑娘说：你一定走了好远的路吧\n",
"小姑娘说：妈总不让我出来玩\n",
//"小姑娘说：其实我已经不小了\n",
        (:do_smile:),
        }) );
        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
     if( !ob || environment(ob) != environment(this_object()) )
         return;
     message_vision( "小姑娘'呀'地叫了一声，显然被$N吓了一跳\n", ob );
             
}

void do_smile()
{
        //string name;
        //name->query_id(thisplayer());
        //    command("shy");
    message_vision("小姑娘羞答答地看了你一眼\n",this_player());
}       

