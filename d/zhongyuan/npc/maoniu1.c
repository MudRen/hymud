inherit NPC;
void create()
{
        set_name("С��ţ", ({ "mao niu","niu" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ų���ë��С��ţ�����ڵ�ͷ�Բݡ�\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 30000+random(20000));

        setup();
}


