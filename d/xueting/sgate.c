// Room: /d/xueting/sgate.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ѩͤ���ϱߵ�Ψһ��ڣ�������������ͨ��ѩͤ��Ľ�
��������������������������ˣ������ǿ��������������������
��ͨ��������Ψһ�ĵ�·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : "/d/cloud/nroad",
  "north" : __DIR__"sstreet1",
  //"east" : "/d/snow/eroad1",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
