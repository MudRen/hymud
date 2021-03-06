// tuihua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_me1();
int ask_me();

void create()
{
        set_name("翠花", ({"cui hua"}) );
        set("nickname", HIG"山野一枝花"NOR);
        set("gender", "女性" );
        set("age", 12+random(6));
        set("long",
          "这是个情蔻初开的小姑娘，听说和踏雪山庄的一弟子两情相悦。\n"
          "手脚勤快，讨人喜爱。见有人稍微示意，便过去加茶倒水。\n");

        set("attitude", "friendly");
        
        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("per", 28);

        set("max_qi", 200);
        set("max_jing", 200);
        set("max_sen", 200);
        set("combat_exp", 2000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 30);
        set_skill("parry", 20);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
/*
         set("inquiry", ([
           "采药道长" : (: ask_me :),
           "rumor" : (: ask_me1 :),
             ]) );
*/
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
        say("翠花笑吟吟地说道：这位" + RANK_D->query_respect(ob)
             + "请先入座，" + "我这就给您上茶。\n");
}

void serve_tea(object who)
{
        object obn;
        object room;

        if( !who || environment(who) != environment() ) return;
        if( !who->query_temp("marks/sit") ) return;
        
        if( !objectp(room = environment()) ) return;
        if ( (int)who->query_temp("tea_cup") <= 0 )
        {
                obn = new("/d/houjizhen/obj/dawancha");
                obn->move(room);
                message_vision("翠花搬出个大茶壶来，将桌上的大碗茶倒满．\n",
                        who);
        } else 
        {
                who->add_temp("tea_cup", -1);
                obn = new("d/d/houjizhen/obj/xiangcha");
                obn->move(room);
                message_vision("翠花拿出个绍兴小茶壶，沏了杯香茶，放在桌上．\n",
                        who);
        }
        obn = new("/d/houjizhen/obj/mitao");
        obn->move(room);
        message_vision("翠花拿出一碟新鲜的水蜜桃，放在桌上．\n", who);
        
        return;
}


/*
int ask_me()
{
        object me, ob;
        ob = this_player();
        me = this_object();
       
        command("nod " + ob->query("id"));
    	command("say 偶尔能在碰见他，为人随和，是个很好的人。\n");
	return 1;
}
int ask_me1()
{
        object me, ob;
        ob = this_player();
        me = this_object();
        if(!ob->query_temp("marks/ask2")){
         command("say " + RANK_D->query_respect(ob) + "想知道那方面的事情？\n");
         return 1;
         }
        command("say 听说有一位老者隐居在后山，人们很少看到他，也不知道是真是假。\n");
        ob->set_temp("marks/taohua",1);
	return 1;
} 
*/ 