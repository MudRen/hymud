 inherit NPC;
void create()
{
        set_name("�ϰ߾���", ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 15);
        set("long", "һ��ˮͰ��ϸ�ľ�����\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", 999999);
        set("bellicosity", 30000 );
        set_temp("apply/attack",200);
        set_temp("apply/damage",150);
        setup();
}   
