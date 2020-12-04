#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "万安寺四楼大厅");
        set("long", @LONG
这里是万安寺四楼的大厅，相当的宽敞。一个明艳少女正座中堂，少女
前方有一块巨大的红木制武器架，左右站满了亲兵，排场很是气派。
LONG );
        set("exits", ([ 
                "down" : __DIR__"was_lou3",
        ]));
        set("objects", ([
                __DIR__"npc/ada" : 1,
                __DIR__"npc/aer" : 1,
                __DIR__"npc/asan" : 1,
                __DIR__"npc/he" : 1,
                __DIR__"npc/zhao" : 1,
                __DIR__"obj/shelf" : 1,
        ]) );

        setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "down") &&
	    objectp(present("luzhang ke", environment(me))))
	{
		return notify_fail("有个人烂住了你。\n");
	}
	
	if ((dir == "down") &&
	    objectp(present("hebi weng", environment(me))))
	{
		return notify_fail("有个人烂住了你。\n");
	}
	
        return ::valid_leave(me, dir);
}