// hen.c
inherit NPC;
void create()
{
        set_name("��ĸ��", ({ "hen" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ���ڵ�����ʳ�Ե���ĸ����\n");
        set("max_gin", 50);
        set("max_kee", 50);
        set("max_sen", 50);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
	"��ĸ��������...����...���Ľ��˼���.\n"
	}));
}
void die()
{
        object ob;
        message_vision("\n$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new(__DIR__"dead_ji");
        ob->move(environment(this_object()));
        destruct(this_object());
}