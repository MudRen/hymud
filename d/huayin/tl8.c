// Room: /d/huayin/tl8.c

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
  "northup" : __DIR__"tl9",
  "southdown" : __DIR__"tl7",
]));

	set("NORIDE","��ô���͵�ɽ·������������ϲ�ȥ��\n");

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
