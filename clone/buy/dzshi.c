// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "����ʯ" NOR, ({ "duanlian shi", "shi"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĶ���ʯ����˵��(use)�ڸɽ������������������벻����Ч����\n");
                set("value", 10000);
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
        message_vision("$N��" + this_object()->name() +
                       "�ó�����ɷۡ�\n", me);

                tell_object(me, HIR "����Щ�ۣ��´ζ�������Ӧ�ò���ʧ���ˡ���\n" NOR);
                me->set_temp("dlwok",1);

        destruct(this_object());
	return 1;
}
