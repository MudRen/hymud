// Room: /d/yeyangzai/caocong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草丛");
	set("long", @LONG
四周是半人多高的杂草丛，你走在其中分不清东南西北，只好碰碰运气
了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" :__DIR__"chalu",
  "west" :__DIR__"chalu",
  "south"  :__DIR__"chalu",
  "north"  :__DIR__"chalu",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
}


