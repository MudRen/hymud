// Room: /u/lots/d/road7.c
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
		"east" : __DIR__"leftroom7",
		"south" : __DIR__"road6",
		"west" : __DIR__"rightroom7",
		"north" : __DIR__"road8",
	]));

	setup();
	replace_program(ROOM);
}

