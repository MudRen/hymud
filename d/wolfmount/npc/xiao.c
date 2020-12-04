 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("萧十一郎", ({ "xiao11","xiao" }) );
        set("gender", "男性" );
        set("age", 25);
        set("per", 27);
        set("reward_npc", 1);
        set("difficulty", 10);

        set("attitude", "peaceful");
        set("max_atman", 300000);
        set("atman", 300000);
        set("class", "wolfmount");
        
        set("max_neili", 3000);
        set("force", 3000);
        set("max_mana", 300000);
        set("force_factor",20);
        set("mana", 300000);
        set("long",     "他全身又干净又整洁，就像一个刚刚剥了壳的鸡蛋。\n");
        set("combat_exp", 9999999);
    set("title", "大盗");

    set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",380);
        set_skill("shayi",380);
         set_skill("aikido",380);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",380);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));

        
        
        
        
        setup();
        carry_object(__DIR__"obj/gelu")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me;
        ::init();
        add_action("do_answer","answer");
        me = this_player();
        if(interactive(me) 
        ) call_out("ask_him", 1,me );  
} 
int ask_him(object me)
{
        if(environment(me) == environment())
   tell_object(me,name()+"问道：到底谁是天宗的新主人？（answer）\n");
        return 1;
}
int do_answer(string arg)
{
object me;
me =this_player();
if(!arg )
return notify_fail(name()+"道：看来你也帮不了我！\n");
if( arg == "lian" || arg == "lian cheng bi" || arg == "连城壁")
{
if(me->query_temp("in_doubt") && me->query_temp("listened"))
{
        if(!me->query("m_success/识破天宗"))
        {
                me->set("m_success/识破天宗",1);
                me->add("score",300);
        }
command("unwield gelu");
command("give gelu to " + me->query("id"));
tell_object(me,name()+"道：你真是一语道破梦中人！好！\n");
return 1;
}
else
return notify_fail(name()+"道：真的吗？没有证据呀！\n"); 
}
else
return notify_fail(name()+"道：我觉得不像！\n");
}    
