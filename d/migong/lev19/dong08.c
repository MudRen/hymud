
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"吵杂之森"NOR);
		set("long", HIG @LONG
    这里是一座古老的原始森林，这里的所有树木看起来都是古老而
沧桑，彷佛历经无数岁月的磨练，但当你走在森林步道上，耳听黄莺
清脆的鸣叫并享受芬多精的薰陶。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong07",
		"south" : __DIR__"dong0"+(random(5)+5),
                "west" : __DIR__"dong09",
                "north" : __DIR__"dong0"+(random(8)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong0"+(random(2)+8),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong0"+(random(5)+1),
                "east" : __DIR__"dong0"+(random(2)+8),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
