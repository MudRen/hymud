// Room: /d/taiwan/road1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条黄泥路,路中给行过的车辆压出了两条深深的车痕.有两三个穿 
着破烂的小孩在路上你追我赶的玩耍.路两边是连绵的水蹈田. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"villege",
  "north" : __DIR__"road",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
