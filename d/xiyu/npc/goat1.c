inherit NPC;
void create()
{
        set_name("Сɽ��", ({ "little goat","goat" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ������Сɽ�����ڵ�ͷ�Բݡ�\n");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 4000+random(2000));
        setup();
}

