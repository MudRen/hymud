// Room: /d/zuojiacun/lu9.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条坑坑洼洼小路，你一脚深一脚浅地走在上面，路过
的村民都赤着双脚，看到你走路的样子，嬉笑地对你指指点点，
你不觉感到脸上一阵发热。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"miao",
  "east" : __DIR__"lu8",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}
