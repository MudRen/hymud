// Room: /d/taiwan/tree8.c

inherit ROOM;

void create()
{
	set("short", "�粨��");
	set("long", @LONG
��ǰ�����ֱ��ϡ������.���µ�С·��������.���������ڿ�����
����Ƭ������.��ͷ�ٿ�,�����ƺ�����Ӱһ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tree4",
  "north" : __DIR__"zhuanyuan",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
