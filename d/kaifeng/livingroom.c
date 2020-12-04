//Room: /u/lots/d/livingroom.c
// LOTS 1998/10/19

inherit ROOM;

void create()
{
	set("short", "包大人的起居室");
	set("long", @LONG
这就是包大人的起居处，你看见周围一尘不染，装饰古朴，而又典雅。显然主人的
是个与众不同的人。在东窗下的桌子上有许多案卷。还有一个靓女站在桌子旁。
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"south" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wife" : 1,
	]));

	setup();
	replace_program(ROOM);
}
