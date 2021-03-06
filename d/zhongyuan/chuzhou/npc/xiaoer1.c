// 楚州客店店小二 /d/city/chuzhou/npc/xiaoer1.c

inherit NPC;

void create()
{
        set_name("店小二", ({ "xiao er","waiter"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "店小二身穿青布衣衫，正笑眯眯地看着你，等你租房。\n"
        );
        set("combat_exp", 10000);
        set("chat_chance_combat", 5);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
        
        set("chat_msg_combat",({
                "店小二大声喊道：“你不要命了，敢在楚州城里杀人放火了？！！！”\n",
                "店小二边打边喊：“杀人啦！！救命啊！！！”\n",
        }) );
        set("inquiry", ([
                "租房" : "“呃，客官要租房？好，一天八两银子。”",
                "住店" : "“客官是要租房吧？”",
        ]) );
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "店小二笑咪咪地说道：“这位" + RANK_D->query_respect(ob)
                + "，进来歇歇脚吧。这里可以住店哪！”\n");
}

int accept_object(object who, object ob)
{
        if( ob->value() >= 8000 ) {
                say("店小二收下钱，笑眯眯地说：“请进，请进！”\n");
                who->set_temp("can_sleep", 1);
                return 1;
        } 
        return 0;
}
