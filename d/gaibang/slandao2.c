// Room: /d/gaibang/slandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG );
	set("exits", ([
		"northeast" : __DIR__"undersl",
		"southwest" : __DIR__"slandao1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

