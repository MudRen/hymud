//wuqiao.c

inherit ROOM;

void create()
{
        set("short", "乌鞘岭");
        set("long", @LONG
你已经进入了河西走廊的东入口.

LONG
        );
        set("exits", ([ 
                "southeast"     :       __DIR__ "lianglu3",            
                "northwest"     :       __DIR__ "lianglu5",
                ])
        );
//      replace_program(ROOM);
        setup();
}

