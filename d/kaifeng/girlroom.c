//Room: /u/lots/d/girlroom.c
// LOTS 1998/10/15

inherit ROOM;

void create()
{
	set("short", "����С��Ĺ뷿");
	set("long", @LONG
���һ���룬�ͱ������װ������ס������С�㲻��ò�������һ��轣���������ڴ�ͷ
����һ֧����
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"houhuayuan",
	]));

	set("objects", ([
		"/d/kaifeng/npc/sister" : 1,
	]));

	setup();
	replace_program(ROOM);
}
