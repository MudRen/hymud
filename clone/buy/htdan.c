// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��Ϳ��" NOR, ({ "ht wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĺ�Ϳ������˵���˿��Լ����ԡ�\n");
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
        if (me->query("int") <= 10)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
{
                tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);
                me->add("int", -1);
}
        destruct(this_object());
	return 1;
}
