#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIY"ǧ�����"NOR, ({ "king gator" }) );
        set("race", "Ұ��");
        set("age", 400);
        set("long", "һ���ɳ������㣬��֪���ⰵ�����������˶�á�\n");
        set("limbs", ({ "ͷ��", "����", "β��", "�۾�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set("combat_exp",5000000);
        set("jing",10000);
        set("qi",10000);
        set("jing",10000);
        set("cps",100);
        set("cor",50);
        set("str",100);
        add_temp("apply/dodge",300);
        add_temp("apply/attack",400);
        setup();
        carry_object(__DIR__"obj/gatorarmor");
}  
