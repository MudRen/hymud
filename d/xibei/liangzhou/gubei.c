//gubei.c

inherit ROOM;

void create()
{
        set("short","西夏古碑");
        set("long", @LONG
西夏国君为记念西夏立国而修的碑.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "zhonglou",    
                ])
        );
//      replace_program(ROOM);
        setup();
}

