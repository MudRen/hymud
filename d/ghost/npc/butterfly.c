 inherit NPC;
void create()
{
        set_name("������", ({ "butterfly" }) );
        set("race", "Ұ��");
        set("per", 30);
        set("age", 1);
        set("yes_carry", 1);
        set("long",
                "һֻ�ۺ�ɫ�ĺ�����\n"
        );
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set_temp("apply/dodge", 100);
        setup();
}
