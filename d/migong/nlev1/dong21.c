#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"石洞"NOR);
	set("long", CYN @LONG
这是一个黑漆漆石洞，周围都是坚硬的石壁,上面隐约传来一丝光亮。 
LONG CYN);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
