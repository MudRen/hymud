#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是商家堡后院西侧的一间厨房，平常商家的弟子们饿了
便可以到这里来要些食物来吃。房中灶火正旺，一个大厨师
正忙的满头大汗。屋角放着一个大水缸。  
LONG);
	set("exits", ([
		"east"  : __DIR__"shang_houyuan",
	]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/shang3" : 1,
               "/clone/food/jitui" : 2,
                "/clone/food/jiudai" : 1,
        ]));
        set("ricewater", 5);
        setup();
}

