// dumpling.c ����
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

mapping *data=({
(["name":"����",	"id":"bread",	"mw":-1,	]),
(["name":"������",	"id":"bread",	"mw":-1,	]),
(["name":"��ţ��",	"id":"bread",	"mw":-1,	]),
(["name":"�����",	"id":"bread",	"mw":-1,	]),				
(["name":"������",	"id":"bread",	"mw":-1,	]),				
(["name":"������",	"id":"bread",	"mw":-1,	]),				
});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������"+query("name")+"��\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
