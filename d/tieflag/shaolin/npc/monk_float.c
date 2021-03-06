 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("和尚", ({ "shaolin monk", "monk"}) );
        create_family("东林寺", 21, "弟子");
        set("gender", "男性" );
        set("age",random(20)+ 32);
        set("nickname","棍僧");
        set("long", "这是东林寺的棍僧，专门负责寺内的警卫工作。\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 500000);
        set("cps",80);
        set("attitude", "friendly");
        set_skill("shaolin-shenfa",120);
        set_skill("dodge",100);
        set_skill("staff", 120);
        set_skill("wuchang-zhang",120);
        set_skill("move",200);
        set_skill("force",200);
        set_skill("parry",100);
        map_skill("staff", "wuchang-zhang");
        map_skill("dodge","shaolin-shenfa");
        map_skill("move","shaolin-shenfa");
        map_skill("parry","wuchang-zhang");
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "staff.powerjam" :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                        "东林和尚说道：不可随便乱走！\n",
                        (: random_move :)
        }) );
        set("neili",100);
        set("max_neili",100);
        set("force_factor",10);
        setup();
   carry_object(__DIR__"obj/monk22_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
}    
