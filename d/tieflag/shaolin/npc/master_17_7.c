 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("�ļ�", ({ "master jian", "master"}) );
        set("gender", "����" );
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
        create_family("������", 17, "����");
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
                "���ص������󷭷��ҷ�������������������������\n",
                "���ص��������������þ���У���\n",
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
        if(inv[i]->query("family/family_name") == "������")
                inv[i]->set("marks/lost_jing_shu",1);   
        message_vision("$N��Цһ���������˾��飬���ű����ʦ�Űɣ�\n",this_object());
        message_vision("$NһԽ���������ڲ����ˣ�����\n",this_object());
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
        if(!killer->query("m_success/�±�����"))
        {
                killer->set("m_success/�±�����",1);
                killer->add("score",300);
                tell_object(killer,WHT"\n��ϲ�㣬������˻���¥������\n"NOR);
                tell_object(killer,WHT"�������������!!!\n\n"NOR);
        }
        }
        ::die(); 
}      
