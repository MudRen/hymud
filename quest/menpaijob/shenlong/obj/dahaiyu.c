// by tie@fengyun
//       "dashayu",
//        "dajqy",
//        "jqy",
//        "dahaiyu",
//        "haiyu",
//        "xiami"
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大海鱼", ({ "dahaiyu" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条大海鱼\n");

	
		set("unit", "条");
		set("value", 400);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
