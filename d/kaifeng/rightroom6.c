//Room: /u/lots/d/rightroom6.c
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
		"east" : __DIR__"road6",
		"west" : __DIR__"rdang6",
		"south" : __DIR__"rightroom5",
		"north" : __DIR__"rightroom7",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
