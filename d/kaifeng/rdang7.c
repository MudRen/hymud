//Room: /u/lots/d/rdang7.c
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
		"east" : __DIR__"rightroom7",
		"south" : __DIR__"rdang6",
		"north" : __DIR__"rdang8",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}
