//Room: /u/lots/d/leftroom6.c
// LOTS 1998/10/14

inherit ROOM;

void create()
{
	set("short", "����������Ϣ��");
	set("long", @LONG
�����Ǵ�����������Ϣ��,�뱣�ְ���.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"west" : __DIR__"road6",
		"east" : __DIR__"ldang6",
		"north" : __DIR__"leftroom7",
		"south" : __DIR__"leftroom5",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
