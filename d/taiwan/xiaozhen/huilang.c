// Room: /d/taiwan/huilang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʯ�������߹�,������һ������,���ų����������������ȳ�����ͨ
������,΢��������µ�ͭ�巢����������.Զ��һ��Ұ������ʲô������
��,����ϸ����,����һ��,�ƺ����˵��ֱ�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chitang",
  "northwest" : __DIR__"dating",
  "northeast" : __DIR__"chufang",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
