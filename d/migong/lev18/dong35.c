
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"岩盘的裂目"NOR);
	set("long", HIY @LONG
    你现在在一个黑暗潮湿的洞穴里，不过奇怪的是虽然这里弥漫著很重
的湿气，墙壁上却是一点青苔也没有。处於这个阴森森的洞穴里，你不由
得打了个机伶伶的冷战 .... 你觉得还是赶快离开这个鬼地方比较好。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("outdoors", "migong");
	set("exits", ([
                "west" : __DIR__"dong3"+(random(5)+4),
		"east" : __DIR__"dong3"+(random(5)+4),
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(5)+4),
                "west" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(8),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

