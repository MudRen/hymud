// r_horse.c
// by dicky

inherit NPC;

void create()
{
	set_name("�����", ({ "yili horse", "horse"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ƥ");
	set("age", 3);
	set("long", "����һƥ�����������\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_sen", 800);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 200);
	set_temp("apply/armor", 300);


	set("ride",1);	// �����ǡ�

	set("ride_level",3);
	setup();
}
