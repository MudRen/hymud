//Room: /u/lots/d/ldang7.c
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
		"west" : __DIR__"leftroom7",
		"south" : __DIR__"ldang6",
		"north" : __DIR__"ldang8",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}
