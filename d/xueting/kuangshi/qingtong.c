// ��ͭ
// edit by pian

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(CYN"��ͭ"NOR, ({ "qingtong" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ���������������������Ʒ����ͭ�顣\n");
		set("unit", "��");
		set("value", 8000);
	}
}