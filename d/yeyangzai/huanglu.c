// Room: /d/yeyangzai/huanglu.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����С·�ϻ������̣����˷�������������ѻ�Ľ����������Ǹ���·�ڣ�
�������ǡ�Ұ��կ���Ĵ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huangye",
  "north" : __DIR__"men",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
