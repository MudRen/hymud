// shuinang.c
// by dicky

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水囊", ({"shui nang", "shuinang", "skin"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是装满清水的水囊。\n");
		set("unit", "只");
		set("value", 200);
		set("max_liquid", 300);
	}

	set("liquid", ([
		"type": "water",
		"name": "天山雪水",
		"remaining": 10,
		"drunk_apply": 30,
	]));
}
