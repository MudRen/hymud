
// crazy_dog.c

inherit NPC;

void create()
{
	set_name("�ǹ�", ({ "wolf dog", "dog" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ�ݼ�צ�����ǹ���һ˫�۾�����ݺݵص����㡣\n");
	set("attitude", "aggressive");
	
	set("str",50 );
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp",61100);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"�ǹ������ͽУ�������������������������\n",
		"�ǹ�ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
	}) );
		
	set_temp("apply/attack", 65);
	set_temp("apply/damage",26);
	set_temp("apply/armor",22);

	setup();
}

