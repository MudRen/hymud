// Room: /d/huayin/tl2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С��·��·�ϵ�������ѹ�ŵĳ��ޣ�·��û��
��������ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"tl1",
  "southwest" : __DIR__"tl3",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
