 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("寒梅先生", ({ "mei" }) );
        set("gender", "男性" );
        set("age", 65);
        set("str", 6);
        set("cor", 24);
        set("cps", 11);
        set("title", HIG "岁寒三友"NOR);
        set("per", 27);
        set("int", 27);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("fly_target",1);
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 500);
        set("neili", 500);
        set("max_mana", 300);
        set("mana", 300); 
        set("long",     "西方神教的三大护法之一\n");  
        set("combat_exp", 999999); 
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 10); 
        map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");
   map_skill("force", "demon-force"); 
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.dimo" :),
                (: perform_action, "unarmed.renmo" :),
                (: perform_action, "unarmed.tianmo" :),
                (: exert_function, "mihun" :),
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/stone")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me;
        me = this_player();
        if(interactive(me) && me->query("marks/冷若霜")
        && (int) me->query("combat_exp") > 20000) call_out("chase_him", 1,me );  
} 
int chase_him(object me)
{
        message_vision("$N向$n喝道：竟敢偷盗本教的罗刹牌！拿来！\n",this_object(),me);
        set_leader(me);
        kill_ob(me);
        me->kill_ob(this_object());
        return 1;
} 
int accept_object(object who, object ob)
{
        if( (string)ob->query("name") == "罗刹牌")
        {
                who->set("marks/冷若霜",0);
                message_vision("$N对$n哼了声：咱们的前嫌旧怨，一＂璧＂勾销！\n",this_object(),who);
                who->remove_all_killer();
                return 1;
        }
        return 0;
}      
