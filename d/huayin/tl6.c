// Room: /d/huayin/tl6.c

inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
����һ����ʯ���̾͵���խ����ɽС·��ʯ�׺ܸߣ������
������ľ�Զ��ʯ�嶼��ĥ����б�£��������������ѡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"tl7",
  "southwest" : __DIR__"tl5",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
