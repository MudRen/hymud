#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
       set("short", YEL"岩洞"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong8",
		"south" : __DIR__"dong5"+(random(5)+1),
                "west" : __DIR__"dong6"+(random(2)+5),
                "north" : __DIR__"dong78",
	]));

         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
