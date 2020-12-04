#include <ansi.h>
inherit NPC;  
void create()
{
        set("long", "这是一伙行商的旅人，他们负重而行，风尘仆仆。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set_skill("unarmed", 200);
        set_skill("iron-cloth", 150);

        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "旅人说：唉，可别遇上马匪才好。\n"
                "商人说：咱们结队而行，有强盗就跟他拼命。\n"
        }) );

        set_name("大漠商旅",({"traveler","desert traveler"}));
        set("force_factor",40);
        setup();
        add_money("silver", 50);
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/towel");
}  
