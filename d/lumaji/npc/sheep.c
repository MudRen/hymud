// sheep.c

inherit NPC;

void create()
{
        set_name("С���", ({ "sheep" }) );
        set("race", "Ұ��");
        set("age", 3);
	set("max_kee", 600);
        set("long", "һֻȫ��ѩ�׵ĵ�����\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 25000);

        setup();
}
