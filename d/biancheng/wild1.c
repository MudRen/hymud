 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "荒原");
        set("long", @LONG
玉龙峰往西，地势平坦。干燥的土地，秋风卷起满天黄沙，在无边无际的荒原
上咆哮而过。本没有路，来往的行人车马多了，踏出一条三尺宽的车道，板结的地
面上满是车辙划过的痕迹。偶尔几骑快马驰过，奔向前方的小镇。
LONG
        );
        set("exits", ([ 
        "northeast" : "/d/eren/yuzhu",
        "west" : __DIR__"wild2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1050);
        set("coor/y",100);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
