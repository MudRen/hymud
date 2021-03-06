 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("心鉴", ({ "master jian", "master"}) );
        set("gender", "男性" );
        set("class", "shaolin");
        set("age", 44);
        set("per", 35);
        set("int",30);
        set("attitude","friendly");
        set("max_neili", 1500);
        set("neili", 1500);
        set("force_factor",50);
        set("long",
"
\n"
        );
        create_family("东林寺", 17, "长老");
        set("combat_exp", 1200000);
        set_skill("move", 100);
        set_skill("dodge", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
        set_skill("unarmed",150);
        set_skill("shaolin-shenfa",150);
        set_skill("jingang-quan",150);
        set_skill("hunyuan-yiqi",100);
        set_skill("staff",100);
        set_skill("parry",100);
        set_skill("pudu-zhang",160);
        map_skill("staff","pudu-zhang");
        map_skill("parry","pudu-zhang");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "yijinjing");
   map_skill("unarmed", "jingang-quan");
        set("chat_chance", 15);
        set("chat_msg", ({
                "神秘的人物左翻翻右翻翻．．．根本不把你放在眼里！\n",
                "神秘的人物用手敲了敲经书盒．．\n",
            (: getting :)
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
            (: getting :),
            (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        setup();
        carry_object(__DIR__"obj/skinmask")->wear(); 
}
void hide()
{
        object *inv;
        int i;
        if( !environment() ) return;
        inv = all_inventory(environment());
        for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("family/family_name") == "东林寺")
                inv[i]->set("marks/lost_jing_shu",1);   
        message_vision("$N阴笑一声：＂丢了经书，等着被逐出师门吧！\n",this_object());
        message_vision("$N一越，跳出窗口不见了．．．\n",this_object());
        call_out("disappear", 1);
} 
void disappear()
{
        destruct(this_object());
} 
void getting()
{
command("get jingshuhe");
call_out("hide",10+random(20));
}
void die()
{
        int i;
        object killer, owner;
        if(objectp(killer = query_temp("last_damage_from")))
        {
        if(owner=killer->query("possessed")) {
                killer = owner;
        } 
        killer->set("marks/protect_jing_shu", 1);
        if(!killer->query("m_success/勇保经书"))
        {
                killer->set("m_success/勇保经书",1);
                killer->add("score",300);
                tell_object(killer,WHT"\n恭喜你，你完成了护经楼的任务。\n"NOR);
                tell_object(killer,WHT"你的评价上升了!!!\n\n"NOR);
        }
        }
        ::die(); 
}      
