// Room: /d/paiyun/lu9.c

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
  "southwest" : __DIR__"lu10",
  "east" : __DIR__"lu8",
  "north" : __DIR__"lin4",
]));

set("objects", ([
	"/d/heifeng/npc/wolfdog":3,
       ]) );

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
