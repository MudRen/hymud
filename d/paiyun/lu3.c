// Room: /d/paiyun/lu3.c

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
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lin1",
  "east" : __DIR__"lu4",
  "southwest" : __DIR__"dayuan",
  "north" : __DIR__"lu10",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
