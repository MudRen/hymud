// Room: /d/heifeng/ling6.c

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
  "eastup" : __DIR__"ling5",
  "west" : __DIR__"ling7",
]));

	set("objects",([
	__DIR__"npc/cutter" : 1,
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}
