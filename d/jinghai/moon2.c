// Room: /d/jinghai/moon2.c

inherit ROOM;

void create()
{
	set("short", "明月崖");
	set("long", @LONG
这里是山冈顶端的边缘。俯视下去可以看见波涛汹涌的拍击
着崖底的岩石。海岛犹如一弯新月般的尽现在一丝薄雾中。又像
一棵明珠镶嵌在碧蓝的海天之中。向北不远处隐约可以看见一做
小亭。西边有一条石子拼铺成的道路通向山下。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"moon23",
  "westdown" : __DIR__"moon3",
  "southeast" : __DIR__"moon1",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
