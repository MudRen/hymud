 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("������", ({ "xi wei", "xi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����������������֮һ��\n");
        set("combat_exp", 80000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("demon-strike",50);
        set_skill("demon-steps",70);
        set_skill("dodge", 80);
        set_skill("force",80);
        map_skill("unarmed", "demon-strike");
        map_skill("dodge","demon-steps");
        set("force",100);
        set("force_factor",20);
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
        if( arg == "north" )
        {
                if( me->query("family/master_name") != "�����") {
        command("say �ǽ������ڵ��Ӳ������ڡ�");
        write("��������·����ס�� ��\n");
        return 1;
                }
                else
                        return 0;
        }
        return 0;
}      
