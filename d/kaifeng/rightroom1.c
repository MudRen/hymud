// Room: /u/lots/d/rightroom1.c
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
		"east" : __DIR__"road1",
		"west" : __DIR__"rdang1",
		"north" : __DIR__"rightroom2",
	]));

	set("objects", ([
		"/d/kaifeng/npc/shiwei" : 2,
	]));

	setup();
	replace_program(ROOM);
}
