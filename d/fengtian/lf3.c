// Room: /d/fengtian/lf3.c

inherit ROOM;

void create()
{
	set("short", "���ŵķ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿ��ŵķ��䡣���˺�������������䡣

LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lf2",
]));

	setup();
	replace_program(ROOM);
}
