#include <ansi.h>
#include <command.h>
inherit NPC; 
int call_guard(); 
void create()
{ 
        set_name("无烟",({"wuyan"}));
        set("long", "风云工作组成员。\n");
        set("title", "杀人不眨眼");
        set("nickname", "杀杀杀");
        set("age",40);
        
        set("group","test");
        set("combat_exp", 8000000);
        set("gender","男性");   
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        set("str",40);
        
        set("max_force",1200);
        set("force",1200);
        set("force_factor",133);
        set("reward_npc", 1);
        set("difficulty", 3); 
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
        ]));
                
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",1);  
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
   
        set("win_msg",CYN"$N冷笑一声：“拖下去，就地正法。”\n"NOR);
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
             // 10:     "\n"+name()+"喝道：反了反了，竟然敢杀官差！！！\n",
             // 100:    (: call_guard() :),
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "无烟说：“杀杀杀。”\n",
        }) );  
        

        setup();
        carry_object(__DIR__"obj/o_cloth")->wear();
      carry_object(__DIR__"obj/sspear")->wield();
}  
