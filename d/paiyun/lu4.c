// Room: /d/paiyun/lu4.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��С·����������ɽ�ֵ�����죬·���������д�����
��פ��·��������ŵ���������ɫ��ζ����wen����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu3",
  "east" : __DIR__"lu5",
  "north" : __DIR__"bingqi",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
