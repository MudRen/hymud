//Room: /u/lots/d/ldang2.c
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
		"west" : __DIR__"leftroom2",
		"south" : __DIR__"ldang1",
		"north" : __DIR__"ldang3",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}
