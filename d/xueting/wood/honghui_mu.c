// ����ľ honghui_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"����ľ"NOR, ({ "honghui mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ��Ʒ�������Ļ���ľ�����������ߵ��Ҿ߻���������̿��\n");
		set("unit", "��");
		set("value", 5000);
	}
}