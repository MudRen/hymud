// Room: /u/lots/d/road8.c
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
		"east" : __DIR__"leftroom8",
		"south" : __DIR__"road7",
		"west" : __DIR__"rightroom8",
		"north" : __DIR__"road9",
	]));

	setup();
	replace_program(ROOM);
}

