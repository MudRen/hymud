// rose.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"��õ��"NOR, ({ "red rose" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ֦�����ĺ�õ�廨��\n");
		set("unit", "֦");
		set("value", 100);
	}
}
