 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"算","余","时","格","已","的","争","那","所","落","们","史"});
        set_name("一"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(20)+ 32);
        create_family("东林寺", 18, "弟子");
        set("long", "这是东林寺的和尚\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(300000)+2000000);
        set("attitude", "friendly");
        set("neili",500);
        set("max_neili",500);
        set("cps",80);
        set_skill("hammer", 70+random(100));
        set_skill("tiexue-hammer",random(100)+150);
        set_skill("dodge",200);
        set_skill("move",180);
        set_skill("force",200);
        set_skill("shaolin-shenfa",150);
        set_skill("jingang-quan",150);
        map_skill("unarmed","jingang-quan");
        map_skill("dodge","shaolin-shenfa");
        map_skill("hammer", "tiexue-hammer");
        map_skill("parry","tiexue-hammer");
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：是时候了吧？\n",
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                name()+"笑道：在东林寺撒野？\n",
                (: perform_action, "hammer.fanbei" :),
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("force_factor",40);
   setup();
        carry_object(__DIR__"obj/monk18_cloth")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}     
