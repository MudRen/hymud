 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�ļ�", ({ "master jian", "jian"}) );
        set("gender", "����" );
        set("age",62);
        create_family("������", 17, "����");
        set("long", "�������ߴ����֮һ��\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(600000)+600000);
        set("attitude", "friendly");
        set_skill("yiyang-zhi", 70+random(100));
        set_skill("unarmed", 100);
        set_skill("dodge",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵�����ؾ����飬�Ϸ���Ը�ڴ����ʮ�ꡣ\n",
        }) );
        set_skill("move",80);
        set_skill("force",200);
        map_skill("unarmed", "yiyang-zhi");
        set("chat_chance_combat", 10);
        set("neili",5000);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
        set("max_neili",5000);
        set("force_factor",55);
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}
void init()
{
        command("say ������ʲô����\n");
        //call_out("do_kick",2+random(3),this_player());
}
