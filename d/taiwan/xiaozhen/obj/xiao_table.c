inherit ITEM;

void create()
{
        set_name("镶银小方桌", ({ "table" }));
        set_weight(20000);
	set("long", "用银箔镶嵌的四方小桌子。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "wood");
		set("value", 2000);
                set("mask","庄");
        }
        setup();
}

