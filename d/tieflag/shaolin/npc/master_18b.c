 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("һǿ", ({ "master yi", "master"}) );
    set("nickname", HIM "��ʦ"NOR);
    set("vendetta_mark","shaolin");
    set("gender", "����" );
    set("age", 64);
    set("agi",30);
    set("skill_public",1);
    set("per", 35);
    set("int",3);
    set("cps",80);
    set("attitude","friendly");
    set("max_neili", 1500);
    set("neili", 1500);
    set("long",
        "
���ִ�ʦ������Ϊ���ֵ�һ�������ɣ����ٰ��࣬�㶼�����Ĺ��͡�\n"
        );
    create_family("������", 18, "����");
    set("combat_exp", 130000000);
    set_skill("luohan-quan",200);
    setup();
    carry_object(__DIR__"obj/monk_cloth")->wear(); 
}
int recognize_apprentice(object ob)
{
    return 1;
}  
