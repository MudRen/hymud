// yak.c
inherit NPC;

void create()
{
	set_name("��ţ", ({ "mao niu","niu" }) );
	set("race", "Ұ��");
	set("age",1);
	set("max_kee",900);
	set("long", "��ţ����һ�߳Բ�һ�߿�����Сţ����\n");

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 70000);
	set_temp("apply/attack",40);
	set_temp("apply/defense",40);
        setup();
}