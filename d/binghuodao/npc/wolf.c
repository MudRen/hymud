// wolf.c
// Date: Sep.22 1997
#include <ansi.h>[D
inherit NPC;

void create()
{
        set_name(HIW"ѩ��"NOR, ({ "wolf", "lang" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���е��ǣ������ŵĴ�����¶�ż��������\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
set("max_qi", 15000);
set("max_jing", 15000);
set("max_neili", 15000);

        set("combat_exp", 200000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2300);
        set_temp("apply/damage", 2300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "ѩ��������β�ͣ�ͻȻ̧ͷ�����㷢��һ�������ĳ�����\n",
                "ѩ������"+HIG" �����ĵ��۹�"+NOR"���������飬Ѫ��޿�������Ź����ӡ�\n",
        }) );
}

void die()
{
        int a;
        object ob,me=this_player();
        a=me->query_temp("marks/bing");
        a=a|1;
        me->set_temp("marks/bing",a);
        ob = new(__DIR__"obj/langpi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

        
