 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","԰"});
        set_name("��"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("class","shaolin");
        set("gender", "����" );
        set("age",random(20)+ 32);
        set("nickname","��ɮ");
        set("long", "���Ƕ����µĹ�ɮ��\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        set_skill("staff", 40+random(100));
        set_skill("wuchang-zhang",random(100)+20);
        set_skill("move",400);
        set_skill("force",200);
        map_skill("staff", "wuchang-zhang");
        set("chat_chance_combat", 30);
        set("neili",100);
        set("chat_msg_combat", ({
                (: perform_action, "staff.powerjam" :),
        }) );
        set("max_neili",100);
        set("force_factor",10);
        setup();
        carry_object(__DIR__"obj/monk23_cloth")->wear();
        carry_object(__DIR__"obj/stick")->wield();
}  
