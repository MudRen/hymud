// ju.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�ƾջ�", ({ "yellow mum" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ֦�����Ļƾջ���\n");
		set("unit", "֦");
		set("value", 100);
	}
}
