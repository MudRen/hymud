//lroad3.c

inherit ROOM;

void create()
{
        set("short","沙土路");
        set("long", @LONG
你离开闹市往北,走一段路,等稍稍远离闹市的喧嚣后, 你发现在前面
不远的绿树从中,忽然露出一角红色的山墙.隐隐有低低的梵唱之声随风而
来.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "center",
                "north"         :       __DIR__ "shanmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

