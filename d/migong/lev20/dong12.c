
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"光之幻境"NOR);
	set("long", HIG @LONG
伟大的众神的力量耀在这个森林中，整个森林闪耀在
一片金黄色的光辉中。在高大树林附近充满著荆棘与矮
灌木,  你发觉你已经迷路了。 
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong34",
		"east" : __DIR__"dong1"+(random(3)+1),
                "south" : __DIR__"dong1"+(random(3)+1),
                "north" : __DIR__"dong1"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(4)+1),
                "west" : __DIR__"dong1"+(random(3)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong34",
                "north" : __DIR__"dong1"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev4" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
