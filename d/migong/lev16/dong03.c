
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"海底过道"NOR);
	set("long", BLU @LONG
这是一条海底过道，不停的有一阵一阵的海浪声从你头上传来....
附近道路很多，四通八达，你感到有种不安全的感觉。
LONG NOR);

	set("exits", ([
		"east" : __DIR__"dong02",
		"south" : __DIR__"dong0"+(random(5)+1),
                "north" : __DIR__"dong04",
                "west" : __DIR__"dong0"+(random(4)+1),
	]));
         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
              "/d/migong/lev18/npc/leva" : random(2),
              "/d/migong/lev18/npc/levb" : random(2),
              "/d/migong/lev18/npc/levc" : random(2),   
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
