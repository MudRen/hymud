// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "Ʒ��ʯ" NOR, ({ "pz shi", "pzshi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĶ���ʯ����˵��(use)�����ڸɽ�����������Ʒ��(levelup)��\n");
                set("value", 10000);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "use");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();

	if ( me->query_temp("lvsjok"))
		return notify_fail("���Ѿ��ù��ˣ���������װ���ɡ�\n");

        message_vision("$N��" + this_object()->name() +
                       "�ó�����ɷۡ�\n", me);

                tell_object(me, HIR "����Щ�ۣ�����ǰ����������һ��װ����Ʒ�ʡ���\n" NOR);
                me->set_temp("lvsjok",1);

        destruct(this_object());
	return 1;
}
