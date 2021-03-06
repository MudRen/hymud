 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("虚寒", ({ "master xu", "master"}) );
    set("nickname", HIR "莲心" NOR);
    set("vendetta_mark","shaolin");
    set("gender", "男性" );
    set("reward_npc", 1);
        set("difficulty", 2);
    set("age", 67);
    set("agi",30);
    set("per", 35);
    set("int",30);
    set("cps",80);
    set("attitude","friendly");
    set("max_neili", 1000);
    set("neili", 1000);
    set("long", "东林第二十代长老，专门传授东林入室弟子武功。\n");
    create_family("东林寺", 21, "长老");
    set("student_title","入室弟子");
    set("combat_exp", 700000);
    set_skill("move", 100);
    set_skill("dodge", 100);
    set_skill("force", 100);
    set_skill("literate", 140);
    set_skill("unarmed",100);
    set_skill("shaolin-shenfa",100);
    set_skill("jingang-quan",100);
    set_skill("yizhi-chan",120);
    set_skill("damo-jian",100);
    set_skill("hunyuan-yiqi",100);
    set_skill("staff",100);
    set_skill("parry",100);
    set_skill("pudu-zhang",100);
    set_skill("blade",100);
    set_skill("xiuluo-dao",100);
    set_skill("tiexue-hammer",100);
    set_skill("hammer",100);
    map_skill("hammer","tiexue-hammer");
    map_skill("staff","pudu-zhang");
    map_skill("parry","xiuluo-dao");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("force", "hunyuan-yiqi");
    map_skill("unarmed", "jingang-quan");
    map_skill("blade","xiuluo-dao");
    setup();
    carry_object(__DIR__"obj/monk21_cloth")->wear();
    carry_object(__DIR__"obj/jiblade")->wield(); 
} 
void attempt_apprentice(object me)
{
    if(me->query("gender") != "男性")
    {
        command("say 东林入室弟子只可以是男弟子。。。\n");
        return;
    }
    if(me->query_temp("won_master_yuan"))
    {
        command("smile");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
        command("shake");
    }
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "shaolin");
}
int accept_fight(object me)
{
    if((me->query("family/family_name") == query("family/family_name") &&
        me->query("family/master_id") == query("id")) ||
       me->query_temp("won_master_yuan"))
    {
        if (me->query("combat_exp")<300000) {
                command("say 徒儿，学武不能好高骛远啊！\n");    
                return 0;
                }
        
        command("say 好，你赢了我，你就可以去找东林中更高深的师傅了！\n");
        return 1;
    }
    else
    {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
    }
}
void win_enemy(object loser)
{
    command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
    command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    winner->set_temp("won_master_xu",1);
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
           return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shaolin"&& userp(victim)&&player!=victim)
        {
            message_vision(HIW
"$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR, this_object(),player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}
