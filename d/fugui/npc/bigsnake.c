 inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIY"���"NOR+BLK"����"NOR, ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һ����������,����ˮͰ�Ľ�ھ�����\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set("agi",100);
        set("combat_exp", 999999);
        set("max_jing",6000);
        set("max_qi",6000);
        set("max_jing",6500);
        set("max_neili",6500);
        set("force",16500);
    set("force_factor",50+random(50));
        set("bellicosity", 50000);
        set_temp("apply/attack",400);
        set_temp("apply/damage",200);
        setup();
}
void die()
{
        object spear;
        object me;
        if (!random(5)) {
        spear = new(__DIR__"obj/yuespear");
        spear->move(this_object());
        }
        ::die();
}       
