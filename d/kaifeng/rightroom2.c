//Room: /u/lots/d/rightroom2.c
// LOTS 1998/10/14
// modified by wind

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
		"east" : __DIR__"road2",
		"west" : __DIR__"rdang2",
		"south" : __DIR__"rightroom1",
		"north" : __DIR__"rightroom3",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
