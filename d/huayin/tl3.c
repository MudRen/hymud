// Room: /d/huayin/tl3.c

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
  "northeast" : __DIR__"tl2",
  "southwest" : __DIR__"tl4",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
