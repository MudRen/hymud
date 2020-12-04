// Room: /u/lots/d/boyroom.c
// LOTS 1998/10/20

inherit ROOM;

void create()
{
	set("short", "包公子的住房");
	set("long", @LONG
这里是包公子的住处,由于从小就受父亲的熏陶,他养成了勤俭的习惯.
周围只有一些古董,靠窗的摆满文房四宝的桌子,和一张木床.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"west" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/boy" : 1,
	]));

	setup();
	replace_program(ROOM);
}
