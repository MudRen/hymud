
// dragon.c

inherit NPC;

void create()
{
	set_name("��צ����", ({ "dragon" }) );
	set("long",
		"����һֻ��������ɽ����צ�����������ϵ���Ƭ��������ҫ�۵Ĺ�â��\n");

	set("race", "Ұ��");
	set("age", 600);
	set("attitude", "friendly");

	set("max_gin", 4000);
	set("max_kee", 6000);
	set("max_sen", 3000);

	set("str", 170);
	set("cor", 150);
	set("cps", 100);
	set("spi", 70);
	set("int", 40);

	set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/armor", 60);

	set("combat_exp", 1000000);
	setup();
}
