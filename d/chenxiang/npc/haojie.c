 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����С����", ({ "toughman" }) );
        set("gender", "����" );
        set("age", 47);
        set("long", "�����һ���������������ˡ�\n");
        set("combat_exp", 10000);
        set("str", 28);
//      set("force", 300);
//      set("max_neili", 300);
        set("force_factor", 1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����С���ܸ�����������ӵĵ��������ˣ���Ҳû����һ����\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/miaodao")->wield();
        add_money("coin", 1);
}       
