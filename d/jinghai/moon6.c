// Room: /d/jinghai/moon6.c

inherit ROOM;

void create()
{
	set("short", "北栈道");
	set("long", @LONG
这是一条用碎石拼铺成的道路，道路两旁整齐的排列着圆木
围墙。道路向南北两个方向笔直的伸延开去。时不时有一队队红
巾水勇鱼贯而过。向北是水寨寨门。南边不远可以看见一大块空
地。东西两侧分别是水寨的伙房和士卒营房的所在。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"moon5",
  "east" : __DIR__"moon13",
  "west" : __DIR__"moon12",
  "south" : __DIR__"moon7",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
