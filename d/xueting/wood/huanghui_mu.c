// ����ľ huanghui_mu.c
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"����ľ"NOR, ({ "huanghui mu" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ��Ʒ�ʲ���Ļ���ľ�����������Ҿ߻����ƺ�̿��\n");
		set("unit", "��");
		set("value", 3000);
	}
}