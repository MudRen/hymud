//Room: /u/lots/d/girlroom.c
// LOTS 1998/10/15

inherit ROOM;

void create()
{
	set("short", "包大小姐的闺房");
	set("long", @LONG
你刚一进入，就被屋里的装饰所惊住，包大小姐不仅貌美，而且会舞剑。所以她在床头
挂了一支剑。
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/sister" : 1,
	]));

	setup();
	replace_program(ROOM);
}
