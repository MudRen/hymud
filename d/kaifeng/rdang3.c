//Room: /u/lots/d/rdang3.c
// LOTS 1998/10/15

inherit ROOM;

void create()
{
	set("short", "��ҵ���������");
	set("long", @LONG
�������ҵ���������.�����˾��ǿ���Щ�������������.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"rightroom3",
		"south" : __DIR__"rdang2",
		"north" : __DIR__"rdang4",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}
