// �׽�ʯ
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"�׽�ʯ"NOR, ({ "baijin stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�ſ��������׽�Ŀ�ʯ�����������Ŀ�ʯ����ұ����һ��׽�\n");
		set("unit", "��");
		set("value", 10000);
	}
}