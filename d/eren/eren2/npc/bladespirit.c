#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("紧那罗王", ({ "jinnaluo" }) );
//      set("nickname",HIC"月光如水"NOR);
        set("title",RED"八部天王之"NOR);
        set("gender", "女性");
        set("age",39);
        set("combat_exp", 1200000);
         set("long",
"月色水波间，仿佛有层淡淡的烟雾升起，烟雾间仿佛有一条淡淡的人影。云开，
月现，月光谈淡的照下来，恰巧照在她的脸上，苍白如月。\n"
        );
        set("max_neili",50000);
        set("neili",50000);
        set("force_factor",120);
        set("max_qi",50000);
        set("max_jing",50000);
        set("max_jing",50000);
                set("con",60);
                set("int",47);
                set("str",50);
                set("cor",80);
                set("agi",40);
                set("per",10);
        set_skill("move",300);
        set_skill("parry", 300);
        set_skill("blade",300);
        set_skill("dodge",300);
  
        setup();

        set_temp("shield_force/type","force");
        set_temp("shield_force/ratio",10000);
        set_temp("shield_force/msg",
                CYN"$n身上的光华消融了$N的攻势。\n"NOR);
        set("revival",1);
} 
