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
	set_name("Ϻ��", ({ "xiami" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һֻϺ��\n");
	
		set("unit", "ֻ");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
