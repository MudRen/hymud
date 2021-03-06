
#define X_TASK_KILL_XINGHU          ( 1 << 12 )

#include <room.h>

inherit ROOM;



void create()
{
    set("short", "密林");
    set("long", @LONG
这里的林子长得异常茂密，人走在林中，不得不经常拨开挡在面前的树叶树
枝；头顶上是密不透光的树林，脚下是齐膝深的长草，常常有蛇伏在草丛中。前
人踏过的路很快就被新长出的枝叶掩住了。
    四周的蚊虫很多，不时在你周围飞舞。
LONG
    );
    set("exits", ([
        "west"     : __DIR__"milin1",
        "east"     : __DIR__"xiao_shancun",
        "north"    : __DIR__"milin2",
        "south"    : __DIR__"milin2",
    ]));
    setup();
}

int valid_leave( object ppl, string arg )
{
    int mark = ppl->GetMark( "xing" );

    if ( mark & X_TASK_KILL_XINGHU && arg == "north" )
    {
        ppl->move( __DIR__"xiaowu" );
        return notify_fail("");
    }
    else
    {
        return ::valid_leave( ppl, arg );
    }
}
