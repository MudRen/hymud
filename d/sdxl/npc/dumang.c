// Npc : /u/poq/sdxl/npc/dumang.c ����
// by poq@jyqx 97/7

inherit NPC;

void create()
{
    set_name("����", ({ "du mang", "mang" }) );
    set("race", "Ұ��");
    set("age", 4);
    set("long", "һ����ڴ�ϸ������ͷ������\n");
    set("attitude", "peaceful");

    set("str", 26);
    set("cor", 30);

    set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
    set("verbs", ({ "bite" }) );

    set("combat_exp", 10000);
    set("max_qi", 24000);
    set("max_jing", 24000);
    set("neili", 24000);
    set("max_neili", 24000);
    set_temp("apply/attack", 150);
    set_temp("apply/defense", 150);
    	set_temp("apply/damage", 3560);
	set_temp("apply/armor", 3560);
    setup();
}

void die()
{
    object ob,ob1;
    ob = this_object();
    message_vision("$Nȫ��Ť�������ڻ��裬��ͷʼ�����Զ������������ã���춽�ֱ������\n", this_object());
    ob1 = new(__DIR__"dan");
    if (ob1) ob1->move(environment());
    destruct(this_object());
}
