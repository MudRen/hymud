// �ڽ�ʯ
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB"�ڽ�ʯ"NOR, ({ "wujin stone" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�ſ��������ڽ�Ŀ�ʯ�����������Ŀ�ʯ����ұ����һ���ڽ�\n");
		set("unit", "��");
		set("value", 10000);
	}
}