//Room: /u/lots/d/rightroom3.c
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
		"east" : __DIR__"road3",
		"west" : __DIR__"rdang3",
		"south" : __DIR__"rightroom2",
		"north" : __DIR__"rightroom4",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
