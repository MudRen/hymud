// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��ò��" NOR, ({ "kar wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĸ�ò������˵���˿��ԼӸ�ò��\n");
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
int i;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");




        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
i=30;
if ( me->query("zhuanshen"))
{
i=50;
}
        if (me->query("kar") > i)
        {

                tell_object(me, "�������ҩûɶζ��������ĸ�Եû������\n");
        } else
{
                tell_object(me, HIR "������ƺ��Լ��ĸ�Ե�����˱仯��\n" NOR);
                me->add("kar", 1);
}


        if (me->query("per") > i)
        {
                tell_object(me, "�������ҩûɶζ�����������òû�����á�\n");
        } else
{
                tell_object(me, HIR "������ƺ��Լ�����ò�����˱仯��\n" NOR);
                me->add("per", 1);
}


        destruct(this_object());
	return 1;
}
