 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("Сɳ��", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",12);
        create_family("������", 23, "����");
        set("long", "���Ƕ����µĺ���\n");
        set("vendetta_mark","shaolin");
        set("class","shaolin");
        set("combat_exp", random(1000)+1000);
        set("attitude", "friendly");
        set("env/wimpy",99);
        set("cps",60);
        set_skill("unarmed", 60+random(10));
        set_skill("jingang-quan",random(10)+70);
        set_skill("move",400);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"���˵�����ĳ�����\n",
        }) );
        set_skill("move",40);
        set_skill("force",20);
        map_skill("unarmed", "jingang-quan");
        set("chat_chance_combat", 10);
        set("neili",50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("max_neili",50);
        set("force_factor",2);
        setup();
        carry_object(__DIR__"obj/monk23_cloth")->wear();
}        
