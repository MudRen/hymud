// ��˿�ľ nan_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"��˿�ľ"NOR, ({ "na mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�鼫Ʒ��˿�ľ�����������ߵ��Ҿ߻����ư�̿��\n");
		set("unit", "��");
		set("value", 10000);
	}
}