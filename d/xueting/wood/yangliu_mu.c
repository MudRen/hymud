// ����ľ yangliu_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"����ľ"NOR, ({ "yangliu mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�����ͨ������ľ�����������Ҿ߻�����ľ̿��\n");
		set("unit", "��");
		set("value", 1000);
	}
}