// Room: /u/lots/d/rxiang.c
// LOTS 1998/10/19

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
ƽ�����������û����õ�ʱ����ڴ�С�Ƭ��,���ǰ���.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"gongtang",
		"northwest" : __DIR__"hualang1",
	]));

	set("objects", ([
		"/d/kaifeng/npc/yahuan" : 2,
	]));

	setup();
	replace_program(ROOM);
}
