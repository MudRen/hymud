// wolf_dog.c

inherit NPC;

void create()
{
        set_name("���ǹ�", ({ "wolf dog","dog" }) );
        set("race", "Ұ��");
        set("age", 3);
	set("long", "����һֻ�ʴ���ǹ�������ëɫ�ͺڣ��۾���ɢ�������͵Ĺ⡣\n");
        set("attitude", "aggressive");

        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        
        set("combat_exp", 50000);
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "���"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",20);
        set("cor",30);
        set("chat_chance", 20);
        set("chat_msg_combat", ({
                "���ǹ�һ��������������!\n",
         }));

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
        setup();
}
