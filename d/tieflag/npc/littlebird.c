 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("һֻСɽȸ", ({ "bird", "little bird" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 1);
        set("long", "����һֻ�ÿɰ���Сɽȸ��\n");
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "���", "�ҽ�", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 1);
        set("chat_msg", ({
"Сɽȸ��ߴ����ߴߴ��������Ҫ�����ԡ�\n",
        }) );
        set_temp("apply/attack", 400);
        set_temp("apply/armor", 40);
        set_temp("apply/dodge",400);
        set("str",60);
        setup();
        carry_object(__DIR__"obj/tongue");
}   
