 inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG"无言"+MAG"怪物"+HIG"制造中心"NOR, ({ "alien queen","queen" }) );
        set("gender", "女性" );
        
        set("age", 32);
        set("str", 25);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("long", "无言怪物制造中心，生产各类疑难怪物。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "怪物制造中心说：给我一两金子，送你一个娃子。\n",               
                }) );   
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);

        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50);
        set("skill_public",1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
