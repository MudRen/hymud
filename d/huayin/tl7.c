// Room: /d/huayin/tl7.c

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
  "southwest" : __DIR__"tl6",
  "northup" : __DIR__"tl8",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}
