// 楚州士兵 /d/city/chuzhou/npc/shibing2.c
// by lala, 1997-12-13

#include <ansi.h>
inherit NPC;

void create()
{
    set_name( "士兵", ({ "shi bing", "bing" }));
    set( "title", YEL"楚州"GRN"守备"NOR );
    set( "age", 25 );
    set( "gender", "男性" );
    set( "long", "一个士兵，略略显的成熟一点，却一副老兵油子的模样。\n" );
    set( "str", 30 );
    set( "con", 30 );
    set( "no_kill", "yangzhou" );
    set( "combat_exp", 8000 );
    set( "max_gin",200 );
    set( "max_qi",400 );
    set( "max_sen",400 );
    set( "chat_chance_combat", 10 );
    set( "chat_msg_combat", ({
        "士兵喝道：“大胆刁民，竟敢杀官，莫不是想造反不成？”\n",
        "士兵喝道：“你还能逃出大宋国界不成，还是乖乖投降吧！”\n",
    }));
    set("talk_msg", ({
        "“边上的那个新兵真烦，整天问这问哪的。”",
        "“楚州可真是个花花世界。”",
        "“站了三年岗了，很快就可以回家了！”",
        "“那个新兵，当了几天兵就想媳妇，哼！”",
    }));

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
	setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
	carry_object("/d/city/npc/obj/jitui")->wear();
}

