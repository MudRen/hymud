#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "黄土路");
        set("long", @LONG
你走在一条蜿蜒的小路上。南边翻个一个小高岗可以回到京城。
LONG );
        set("exits", ([
                "east" : __DIR__"road2",
        "south" : "/d/heimuya/road3",
        ]));

        set("outdoors", "beijing");
        setup();
}
