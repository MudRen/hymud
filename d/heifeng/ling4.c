// Room: /d/heifeng/ling4.c

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
  "northup" : __DIR__"ling3",
  "southdown" : __DIR__"ling5",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
