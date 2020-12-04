 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "jin wei", "jin"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����������������֮һ��\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("demon-strike",10);
        set_skill("demon-steps",30);
        set_skill("dodge", 40);
        set_skill("force",40);
        map_skill("unarmed", "demon-strike");
        map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",2);
        set("max_neili",100);
        create_family("�������", 7, "����");
        set("chat_chance", 10);
        set("chat_msg", ({
                "��������ȵ�������Ŀ����\n",
                "��������ȵ���վס����������ƣ� û���ƾ�����Ѫ��������\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/blackrobe")->wear();
}      
