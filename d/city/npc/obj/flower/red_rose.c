//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIR "��õ��" NOR, ({"hong meigui", "red rose"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�京�����ŵ����õ�壬������������������\n");
		set("unit", "��");

		set("value", 30000);
		set("base_unit", "��");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
	 
}
#include "flower.h"