// eyu.c
// by dicky

inherit NPC;

void create()
{
        set_name("����", ({"e yu","eyu"}));
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һ���ſ�Ѫ���ڵ����㡣\n");
        set("attitude", "aggressive");

        set("str", 35);
        set("cor", 35);

        set("limbs", ({ "ͷ��", "����", "�Ų�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);

	set_temp("apply/attack", 300);
	set_temp("apply/damage", 250);
        set_temp("apply/armor", 350);

        setup();
}

void unconcious()
{
        object ob;
        message_vision("$N�鴤�˼��£���������һ�����ˡ�\n", this_object());
        ob = new(__DIR__"obj/wuming-blade");
        ob->move(environment(this_object()));
        destruct(this_object());	
}
