// ��ͭʯ
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"��ͭʯ"NOR, ({ "qingtong stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�ſ���������ͭ�Ŀ�ʯ�����������Ŀ�ʯ����ұ����һ����ͭ��\n");
		set("unit", "��");
		set("value", 100);
	}
}