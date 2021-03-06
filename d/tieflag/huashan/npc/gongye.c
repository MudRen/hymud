 // hawktrainer.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int train_animal();
void create()
{
        set_name("公冶长", ({ "gongye chang","gongye" }) );
        set("gender", "男性" );
        set("age", 34);
        
        set("long", @LONG
他的眼睛总是眯着的。似乎永远都是在侧耳聆听什么。 
LONG
);
        set("skill_public",1);
        set("inquiry",([
        "训兽术" : (: train_animal :),
        "animal training" : (: train_animal :),
    ]) );
     set("neili", 36400);
        set("max_neili", 36400);
        set("jiali", 50);
        set("max_qi",18200);
        set("max_jing",15200);

        set("combat_exp", 5400000);
        set("shen", 20000);
        set_temp("xunshan", 200);
        set("apprentice_available", 3);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );


        set_skill("unarmed", 180);
        set_skill("sword", 290);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 200);
        set_skill("huashan-sword", 290);
        set_skill("zixia-shengong", 320);
        set_skill("hunyuan-zhang", 290);
        set_skill("poyu-quan", 290);
        set_skill("feiyan-huixiang", 290);
        set_skill("pixie-sword",280);
        set_skill("zhengqijue",200);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object me;
        ::init();
        if(interactive(me = this_player()) && !is_fighting() && userp(me))
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, me);
                        
        }
} 
int greeting(object me)
{
        object crow;
        if( !me || environment(me) != environment() ) return 0;
        if (random(3) || me->query("per")<=15)
        {
        message_vision("$N看了$n一眼，欲言又止。 \n",this_object(),me);
        }else
        {
                if (crow = present("crow",environment()))
                {
                        message_vision("$N看了$n一眼，笑对$n说：“你知道它在说什么吗？它在说："+YEL"\n 公冶长 公冶长 ,\n 崖后摔死一头狼。\n 子食肉，我食肠。” \n"NOR,this_object(),me);
                        crow->followme(me);
                }
        }
        
}
void accept_player(object player)
{
        object wolfmeat;
        if (player && present(player,environment()))
        {
                message_vision("不一会而功夫，$N收拾好了死狼。\n",this_object());
                message_vision("$N对$n道：“内脏我留着给我的乌鸦，狼肉给你。”\n",this_object(),player);
                wolfmeat = new(__DIR__"obj/wolfmeat");
                if (wolfmeat->move(player))
                {
                        message_vision("$N递给$n一块狼肉脯。\n",this_object(),player);
                }
                if( player->query_temp("followcrow") && !player->query("marks/getwolf")) 
                {
                        message_vision("$N道：“我一直担心我的训兽术失传，这位"+ RANK_D->query_respect(player) +"既与我投缘，
若不嫌弃，我可以教你几手。”\n",this_object());
                        player->set("marks/getwolf",1);
                        player->delete_temp("followcrow");
                } 
        }
} 
int accept_object(object who, object ob)
{
        if(ob->query("id") != "deadwolf")
    {
                return 0;
    }
    message_vision("$N笑咪咪对$n道：“这位"+ RANK_D->query_respect(who) +"真是聪明!”\n",this_object(),who);
        message_vision("$N高兴地接过死狼，开始剥皮开割。\n \n",this_object());
        call_out("accept_player",2,who);
        return 1;
}  
int train_animal()
{
        message_vision("$N道：“训兽术是一门很有用的技能，如果你掌握了训兽术，你就可训练万兽，让它们听从你，为你服务。”\n", this_object());
        return 1;
}
int recognize_apprentice(object ob)
{
        if (this_player()->query("marks/getwolf"))
                return 1;
        else
                return 0;
}     
