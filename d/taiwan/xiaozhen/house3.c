// Room: /d/taiwan/house3.c

inherit ROOM;

void create()
{
	set("short", "财主大门");
	set("long", @LONG
当地财主白剥皮的家院,门口的乌木大门敞开着,高高的门坎上骑着
个看门的大汉,两边的石狮子很是威武.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
  "enter" : __DIR__"dayuan",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
