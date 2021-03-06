// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("牛皮水袋", ({"shuidai", "skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装水的大水袋，大概装得八、九升的水。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 25);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

