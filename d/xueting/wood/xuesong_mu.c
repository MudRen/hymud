// ѩ��ľ xuesong_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"ѩ��ľ"NOR, ({ "xuesong mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ����Ա�����ѩ��ľ����������ƽ���Ҿ߻����ƽ�̿��\n");
		set("unit", "��");
		set("value", 2000);
	}
}