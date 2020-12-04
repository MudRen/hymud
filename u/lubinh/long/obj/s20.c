inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("小炒粉丝", ({ "xcfs", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盘名厨烹调的上好大菜。\n");
		set("unit", "盘");
		set("food_remaining", 15);
		set("food_supply", 160);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
        set_name("盘子", ({"panzi"}));
        set("long", "一只蓝底儿雕花的景泰蓝大盘子。\n");
        return 1;
}
