// Room: /d/jinghai/jhd13.c

inherit ROOM;

void create()
{
	set("short", "弟子休息室");
	set("long", @LONG
这是一间宽敞的大房间，里面除了几张大床什么也没有，靖
海的弟子晚间或者练功之余都来这里休息。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd10",
]));

	
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
