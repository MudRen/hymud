// Room: /d/paiyun/ta2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ķ������߻�Ȼ���ʣ���ľȺɽ���͵��֣���ĿԶ
������һ��ȺɽС���⾳����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"ta2",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
