// donkey.c

inherit NPC;

void create()
{
        set_name("ë¿", ({"donkey"}));
        set("race", "Ұ��");
        set("age", 10);
        set("combat_exp", 10000);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite"}));

	set("ride",1);

        set("ride_msg", "$N�����ڵ�����ë¿��");
	set("unride_msg","$N��¿������������");

        set("ride/dodge", 1);
        set_temp("apply/attack", 20);
        set_temp("apply/armor", 40);

        setup();
}