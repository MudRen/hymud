 inherit NPC;
void create()
{
        set_name("����", ({ "yan zi", "yan" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("yes_carry", 1);
        set("long",
                "һֻС���ӡ�\n"
        );
        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set_temp("apply/dodge", 100);
        setup();
}    
