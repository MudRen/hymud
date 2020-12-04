
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"海边草原"NOR);
	set("long", GRN @LONG
 这起伏不大的丘陵上长满了嫩绿的鲜草，而点缀其上的小白花，使这
里令人觉得精神愉快，站在这儿可以看到远方的大海，这是因为这里都没
有高大的植物。
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong1"+(random(8)+1),
                "north" : __DIR__"dong20",
	]));
if (random(3)==0)
	set("exits", ([
		          "north" : __DIR__"dong20",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong1"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(3),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
