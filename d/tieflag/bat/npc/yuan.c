#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("原随云", ({ "master yuan suiyun", "yuan suiyun","master"}));
    set("long",
        "
他笑容温柔而亲切，但一双眼睛里，却带着种说不出的空虚、寂寞、萧索
之意, 是个很秀气，很斯文的少年，穿着虽华丽，但却不过火。
\n"
        );
    set("title","无争山庄少主人");
    set("nickname", HIR "蝙蝠公子"NOR);
    set("gender", "男性");
    create_family("蝙蝠岛", 1, "岛主");
    set("student_title","弟子");
    
    set("class","bat");
    set("reward_npc", 1);
    set("difficulty", 25);
    set("fly_target",1);
    set("age", 26);
    set("int", 40);
    set("con", 20);
    set("per", 40);
    
    set("atman",1000);
    set("max_atman",1000);
    set("neili", 2000);
    set("max_neili", 2000);
    set("force_factor", 100);
    set("combat_exp", 80000000);
    set("attitude", "friendly");
    
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
            (: perform_action, "dodge.huanyinqianchong" :),
            (: perform_action, "blade.shiwanshenmo" :),
            }) ); 
    set("chat_chance", 1);
    set("chat_msg", ({
        "原随云走到琴边，一首如行云流水般的曲子从他指间溢出。
世间己有很久没有过如此悦耳的琴声了。\n ",
            "\n",
        }) );
        
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
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

    set("ranks",({"弟子","小邪","少邪","玄武神","朱雀神","白虎神",
                      "青龙神","副岛主"}));
    set("rank_nogen",1); 
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object(__DIR__"obj/hanhai")->wield();  
} 
void attempt_apprentice(object ob)
{
    if (ob->query("combat_exp") < 3000000) {
        command("say  这么差的武功，怎么学得会我的刀法？");
        return;
        }        
    if( (int) ob->query_temp("marks/murderhu") == 1 )
     {
        command("say 很好，很好，蝙蝠岛正需要你这样胆大包天、横行无忌的人才！");
        command("recruit " + ob->query("id"));
     }
     else     command("say 你听没听过借刀杀人这句话 ？我现在想借阁下的刀。。。");
}  
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bat");
        ob->add("betrayer",-1);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
//      ob->add("score",-5000);
}
