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
	set_name("大鲨鱼", ({ "dashayu" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条大鲨鱼\n");

	
		set("unit", "条");
		set("value", 800);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
