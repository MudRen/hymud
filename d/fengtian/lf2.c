// Room: /d/fengtian/lf2.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
����һ���쾮�������в��ٻ����ݲݡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lf1",
  "east" : __DIR__"lf3",
]));

	set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
