// Room: /u/lots/d/road9.c
// LOTS 1998/10/14

inherit ROOM;

void create()
{
	set("short", "���⸮ͨ��");
	set("long", @LONG
�����ǿ��⸮��ͨ��,·�����Ǵ�����������Ϣ������ҵ�������,�ɴ���,
���Ե����⸮�Ĺ���,���Ƕ�����Ը�״.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"leftroom9",
		"south" : __DIR__"road8",
		"west" : __DIR__"rightroom9",
		"north" : __DIR__"gongtang",
	]));

	setup();
	replace_program(ROOM);
}

