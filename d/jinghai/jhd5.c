// Room: /d/jinghai/jhd5.c

inherit ROOM;

void create()
{
	set("short", "环岛小路");
	set("long", @LONG
这是一条依山而建环绕全岛的小路，路的一侧是繁密的杉树
林，一侧就是烟波浩淼的大海了。路很窄，海浪咆哮着扑向岸边，
但立刻便被嶙峋的乱石击得粉碎，炸成无数的水珠溅在你身上。
迷朦的水雾把这条小路重重的围裹着，你有点不能确定是不是应
该继续往前走了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jhd3",
  "south" : __DIR__"jhd6",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
