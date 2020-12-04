inherit ROOM;

void create()
{
        set("short", "山庄厨房");
        set("long", @LONG
这里就是山庄厨房.
LONG
);

        set("exits", ([
                "north"  : __DIR__"taohuayuan",
]) );
        set("objects", ([
            __DIR__"obj/mifan"       : 3,
        ]));


        setup();
}
void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");

        message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
        me->add("water", 20);
        return 1;
}


