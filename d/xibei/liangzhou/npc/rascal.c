//  rascal.c    飞贼
//Hydra


#include <ansi.h>
inherit NPC;

void create()
{
    seteuid(getuid());
    set_name("飞贼", ({ "fei zei", "zei","rascal" }) );
    set("title","采花大盗");
    set("gender", "男性" );
    set("age", 30);
    set("str", 28);
    set("int", 30);
    set("per",24);
    set("combat_exp", 500000);
    set("social_exp", 30000);
    set("attitude", "killer");
       
    set("force", 2000);
    set("max_force", 2000);
    set("force_factor", 150);

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
    carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
    object ppl = this_player();
    ppl->delete_temp("凉州");
    ppl->set("凉州/lose",1);
    kill_ob(ppl);
    ppl->kill_ob(this_object());
}

void die()
{
    object killer;
    killer = this_object()->query_temp( "last_damage_from" );
    message_vision("$N惨笑一声，“想不到我快活一世，却栽在你的手上。。。\n",
        this_object());
    killer->delete("凉州/lose");
    killer->set("凉州/win",1);
    killer->add("hydra/shaolin/pending_kaoyan",1);
    ::die();
}
