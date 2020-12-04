
// snake.c

inherit NPC;

void create()
{
        set_name("����", ({ "snake" }) );
	set("race", "Ұ��");
	set("age", 4);
        set("long", "һ�����ߺ���·�У�����ע�⵽�����ⲻ��֮�͡�\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 400);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
                "��ͻȻ�������ӣ���������������Ѫ�����ͷ\n",
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}
