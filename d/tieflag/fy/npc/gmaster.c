 // teacher.c
//Modified by justdoit 04/11/2001 
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("查猛", ({ "meng", "zha meng" }) );
    set("nickname", HIY "金狮掌"NOR);
    set("gender", "男性" );
    set("age", 32);
    set("skill_public",1);
    set("reward_npc", 1);
    set("difficulty", 4);
    
    set("neili",500);
    set("force_factor",20);
    set("max_neili",500);
    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        "护镖" : (: test_dart :),
       ]));
    set("int", 30);
    create_family("少林", 21, "俗家弟子");
    set("long",
        "金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
凡是想向他求教的，只要为镖局出点力，他就肯教．\n"
        );
    set("chat_chance", 2);
    set("chat_msg", ({
        "查猛说道：这个月镖局生意不错！\n",
            "查猛说道：护镖（ｍｉｓｓｉｏｎ）的事．．．．\n",
            }) );
    set("attitude", "peaceful");
                switch (random(3)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                   break;
                default: set("resistance/kee",30);
                }
    
    set_skill("unarmed", 150);
        set_skill("xianglong-zhang",250);
        set_skill("dodge", 150);
        set_skill("move",200);
        set_skill("parry",150);
        set_skill("wuxing-dun",150);
        
        map_skill("dodge","wuxing-dun");
        map_skill("unarmed","xianglong-zhang");
        
    
    set("combat_exp", 3500000);
    setup();
    carry_object(__DIR__"obj/jinzhuang")->wear();
} 
