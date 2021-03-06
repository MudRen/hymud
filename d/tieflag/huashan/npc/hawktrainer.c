 // hawktrainer.c
#include <ansi.h>
inherit NPC;
void followhim(object ob); 
void create()
{
        set_name("驯鹰人", ({ "hawk trainer","trainer" }) );
        set("gender", "男性" );
        set("age", 34);
        
        set("long", @LONG
他脸上戴着个奇怪的眼罩，看着活象个大熊猫。
LONG
);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 40);
        set("resistance/kee",100);
        set("resistance/gin",100);
        set("resistance/sen",100);
    
    set("max_jing", 30000);
    set("max_qi", 30000);
    set("max_sen", 30000);
    set("eff_jing", 30000);
    set("eff_qi", 30000);
        set("eff_sen", 30000);
            set("jing", 30000);
            set("qi", 30000);
            set("sen", 30000); 
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 3000);
        set("neili", 3000);
        set("max_mana", 300);
        set("mana", 300);
        set("str", 200);
        set("cor", 30);
        set("cps", 25);
        set("per",5);
   set("agi", 40);
        set_skill("move",300);
        set_skill("unarmed",200);
        set_skill("dodge",200);
//       set_skill("perception",200);
    set("combat_exp", 20000000);
        set("attitude", "friendly");
    set("chat_chance", 1);
        set("chat_msg", ({
"驯鹰人对着苍鹰恨恨地嘀咕：公冶长是骗子！这个瘟头鹰就是不听话！ \n",
"驯鹰人说：等我驯好猎鹰，什么敌人都逃不出手心！\n",
}) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/eyecover.c")->wear();
        carry_object(__DIR__"obj/leathersleeves.c")->wear();
} 
void init()
{
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting() && userp(ob))
        { 
                if((string) ob->name() == "公冶长" )
                {
                        
                        remove_call_out("followhim");
                        //message_vision((string) ob->name(),this_object());
                        call_out("followhim", 2, ob);
                        
                }
        }
        //add_action("do_catch","catch");
        add_action("do_kill","kill");
}
void check_status(object ob)
{
        remove_call_out("check_status");
        if (!objectp(ob) || !present(ob, environment(this_object())))
        {
           
                message_vision("公冶长先生哪里去了? \n",this_object());
                message_vision("我得回去看看我的猎鹰！ \n",this_object());
                set_leader(0);
                set("chat_chance", 1);
                this_object()->move(__DIR__"fupi");
                return;
        }
        else
        {
                if((string) ob->name() != "公冶长" )
                {
                        //remove_class_out("check_status");
                        
                        message_vision(" $N对$n大喝道：你不是公冶长！！ 你是哪里来的骗子？！\n", this_object(),ob);
                        message_vision("我得回去看看我的猎鹰！ \n",this_object());
                        set_leader(0);
                        set("chat_chance", 1);
                        this_object()->move(__DIR__"fupi");
                        return;
                }
        }
        message_vision("$N对$n求道：公冶长先生，我按您的方法训练了。可猎鹰就是不听话，求求您再给指点指点吧！\n",this_object(),ob);
        call_out("check_status",10,ob);
        return;
} 
void followhim(object ob)
{
        object room;
        room = find_object(__DIR__"fupi");
        if(environment() == room)
                if( present(ob, environment()))
                {       
                        message_vision( HIY"驯鹰人一看见$N，大喜过望：“公冶长先生您终于来了！您再给指点指点吧！”\n"NOR,ob);
                        set_leader(ob);
                        set("chat_chance", 0);
                        call_out("check_status",10,ob);
                }       
} 
/*
int do_catch(string arg)
{
    if (arg == "hawk" || arg=="苍鹰")
    {
        message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}
*/
int do_kill(string arg)
{
    if (arg == "hawk" || arg=="苍鹰")
    {
        message_vision(RED"$N对$n大吼一声：想打我猎鹰的主意！你活得不耐烦了！ \n"NOR,
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}  
