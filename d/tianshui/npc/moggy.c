// moggy.c
inherit NPC;

void create()
{
	set_name("ţ��", ({ "niu du", "du" }) );
	set("race", "Ұ��");
	set("age",1);
	set("max_kee",800);
	set("long", "��ţ����һ�߳Բ�һ�߿�����Сţ����\n");

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 70000);
	set_temp("apply/attack",40);
	set_temp("apply/defense",50);
	set_temp("apply/damage",20);
	set_temp("apply/armor",20);
	setup();
}
