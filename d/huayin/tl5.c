// Room: /d/huayin/tl5.c

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
  "northeast" : __DIR__"tl6",
  "west" : __DIR__"xiaolu7",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
