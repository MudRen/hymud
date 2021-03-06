#include <room.h>
#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", "金沙江渡口");
        set("long", @LONG
金沙江源出西域昆仑山下，水势湍急，两岸俱是数百丈高的悬崖，只在渡口
附近有一小块河滩沙地，南面有一条羊肠小道曲折地穿进山里。北面渡口也有一
条小道进入山中。天上不时飞过几只大鸟。
LONG
        );
        set("exits", ([
                "south"     : __DIR__"dukou1",
                "northeast"  : __DIR__"shanlu01",
        ]));
        set("item_desc", ([
                "river":  "大江的波涛巨响震得脚下的大地都颤动起来。\n",
        ]));
        setup();
        set("outdoors","xinan");
}
void init()
{       
        write(BLU "江水汹涌而下，巨大的声响震得你心惊胆战!\n" NOR);
}
