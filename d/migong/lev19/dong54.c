
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"龙之谷"NOR);
	set("long",HIW @LONG
   你现在在一个空汤的山谷里，四周一片空空汤汤，只有碧蓝的天空和天
空中的白云静静地立著。凛冽的寒风由四面八方吹来，令你觉得有些寒冷。
「哪来的这麽大风？」你的心中不由得纳闷著。  
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong55",
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(5)+1),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+1),
		"east" : __DIR__"dong4"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(5)+1),
		"north" : __DIR__"dong4"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 2,
              __DIR__"npc/lev4" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

