
// roc.c

inherit NPC;

void create()
{
	set_name("��ڤ����", ({ "roc" }) );
	set("long",
		"����һ�����Ա�ڤ����Ĵ������Ӷ��������쫷���԰��˴��ܡ�\n");

	set("race", "Ұ��");
	set("age", 200);

	set("max_gin", 500);
	set("max_kee", 2000);
	set("max_sen", 1100);

 set("str", 30);
	set("cor", 40);
	set("spi", 40);
	set("int", 20);

	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
	set("verbs", ({ "bite", "claw", "poke" }) );

  set_temp("apply/attack", 150);
	set_temp("apply/damage", 40);
	set_temp("apply/dodge", 70);
	set_temp("apply/armor", 30);

 set("combat_exp", 2000000);
	setup();
}
