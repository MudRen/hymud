//  beihubian.c 
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "北湖边");
        set("long", @LONG
这湖作椭园之形，大半部隐在花树丛中，东南西北尽是悬崖峭壁，只有
刚爬下来的山坡比较最斜，其他各处决计无法攀上，湖畔生长着一丛丛的茶
花，摇夷生姿。湖水清澈，闪着银光。
LONG
        );
        set("resource/water", 1);
        set("outdoors", "大理");
        set("exits", ([
                "northeast" : __DIR__"donghubian",
		"southeast" : __DIR__"nanhubian",
                "north" : __DIR__"shulin4",
        ]));

        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在湖边用手捧了一些水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口从山上瀑布流淌下来的湖水，甘美异常。\n");
        }
        else write("喝那么多的凉水，你不怕生病吗?\n");
        return 1;
}
