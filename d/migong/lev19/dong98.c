#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"飞船之遗迹"NOR);
	set("long", CYN @LONG
   传说这是一艘叫做天马号的飞船，是魔法王国的遗物，据说以前是
一座飞在天空的城市，不知什么时候掉到了这里。你说在的地方依稀还
看的到是甲板的样子，附近雾气重重，雾中的杀气越来越浓了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong99",
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong99",
	]));

	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/lev9" : 2,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
	replace_program(ROOM);
}
