// Room: /d/paiyun/ta1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ķ������߻�Ȼ���ʣ���ľȺɽ���͵��֣���ĿԶ
������һ��ȺɽС���⾳����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"ta1",
]));

	set("objects", ([
		__DIR__"npc/d_guard" : 3,
	]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
