// Room: /d/heifeng/ling2.c

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
  "northup" : __DIR__"up2",
  "southdown" : __DIR__"ling3",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
