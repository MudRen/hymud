//Room: /u/lots/d/rightroom8.c
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
		"east" : __DIR__"road8",
		"west" : __DIR__"rdang8",
		"south" : __DIR__"rightroom7",
		"north" : __DIR__"rightroom9",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
