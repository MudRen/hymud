// Room: /d/heifeng/ling5.c

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
  "northup" : __DIR__"ling4",
  "westdown" : __DIR__"ling6",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
