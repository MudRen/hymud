// Room: /d/paiyun/lu10.c

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
  "south" : __DIR__"lu3",
  "northeast" : __DIR__"lu9",
  "north" : __DIR__"zhucang",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
