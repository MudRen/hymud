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
	set_name("��ǹ��", ({ "jqy" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����ǹ��\n");

	
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
