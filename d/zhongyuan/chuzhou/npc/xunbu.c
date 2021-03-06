// 楚州巡捕 /d/city/chuzhou/npc/xunbu.c
// by lala, 1997-12-13

#include <ansi.h>

inherit NPC;



void create()
{
    set_name("巡捕", ({ "xun bu", "bu", "constable" }));
    set("gender", "男性");
    set("age", 35);
    set("title", GRN"楚州"YEL"官差"NOR),
    set("long", "他是一个巡捕，腰跨钢刀，一副精明干练的样子。\n");

    set("no_leave_chuzhou", 1);

    set("str", 30);
    set("con", 30);

	set("combat_exp", 310000);
	set("shen_type", 1);

    set("max_neili",5500);
    set("neili",5500);
    set("qi",5500);
    set("eff_qi",5500);
    set("max_qi",5500);

    set("jing",5500);
    set("eff_jing",5500);
    set("max_jing",5500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

    set("combat_exp", 50000);
    set("chat_chance", 45);
    set("chat_msg", ({
        "巡捕东看看，西看看，一付要找人晦气的样子。\n",
        "巡捕喝道：“闪开闪开，干什么呢！”\n",
        (:random_move:),
    }) );
    set("talk_msg", ({
        "“从楚州可以逆淮水而上到泗州去。”",
        "“自从运河上的船只在这儿停靠的多了以后，地面上的泼皮也多了。”",
        "“你是练武的人吧？扬州的镖局据说很有名。”",
        "“要是有什么冤情，你可以到衙门去申冤。”",
        "“从楚州过淮水很方便，这里有个渡口。但是河那边是什么地方，我不知道。”",
        }) );
    setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();
}


