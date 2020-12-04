 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("������", ({ "tie wei", "tie"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����������������֮һ��\n");
        set("combat_exp", 40000);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
        set_skill("demon-strike",40);
        set_skill("demon-steps",60);
        set_skill("dodge", 70);
        set_skill("force",70);
        map_skill("unarmed", "demon-strike");
        map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",15);
        set("max_neili",100);
        create_family("�������", 7, "����");
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������ȵ��������߶���\n",
                "����������ȵ���������ʲô��\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/blackrobe")->wear();
} 
void init()
{
        add_action("do_gogo", "go");
} 
int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( arg == "south" )
        {
                if( me->query("class") != "bandit") {
        command("say ��������̽��ڲ������ڡ�");
        write("��������·����ס�� ��\n");
        return 1;
                }
                else
                        return 0;
        }
        return 0;
}     
