// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "������·��" NOR, ({ "nb wan", "nbwan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĳɳ�������˵���˿������Ӿ���Ǳ��������\n");
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

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

                tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);
                me->add("combat_exp", 100000);
                me->add("potential", 80000);
                me->add("max_neili", 80);
                me->add("mpgx", 8);


        destruct(this_object());
	return 1;
}
