// Room: /d/heifeng/ling3.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ�����͵�С·��խ��ֻ����һ�����ߣ�������������
�£������ǳ���������ʯ�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"ling2",
  "southdown" : __DIR__"ling4",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
