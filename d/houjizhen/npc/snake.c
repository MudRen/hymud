// snake.c
// by dicky

inherit NPC;

void create()
{
        set_name("��Ҷ��", ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һ�����̵��ߣ�����ϸ���Ὣ�����ܱ߱��̵���Ҷ��Ϊһ�塣\n");
        set("attitude","killer");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 6000);

        set_temp("apply/attack", 20);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 1);

        setup();
}
 
