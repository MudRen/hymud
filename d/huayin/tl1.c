// Room: /d/huayin/tl1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����С��·��·�ϵ�������ѹ�ŵĳ��ޣ�·��û��
��������ڶ�������������Լ�������Ĵ��̡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaolu1",
  "southwest" : __DIR__"tl2",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
