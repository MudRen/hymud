//gubei.c

inherit ROOM;

void create()
{
        set("short","���Ĺű�");
        set("long", @LONG
���Ĺ���Ϊ���������������޵ı�.
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

