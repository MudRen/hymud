// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "ƽ��" NOR, ({ "ps wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ�ƽ�񵤣���˵���˿��Ըı����ʦ�š�\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;
int max;
        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        max = me->query_skill("force")*10 + me->query("combat_exp")/1000;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        me->delete("family");
        me->delete("class");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "��ͨ����");
        me->set("class","0");
        me->delete("party");
//me->clear_condition("killer");
tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);

        destruct(this_object());
	return 1;
}
