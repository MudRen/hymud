// Room: /d/changan/kezhan5.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间很小的客房，陈设十分简陋但非常干净。靠墙放了
一张木床，墙上开了一扇不大的窗户。
LONG
);
	
	set("sleep_room", 1);
	
	set("hotel",1);

	set("exits", ([
		"east" : __DIR__"kezhan2",
	]));

	setup();
//	create_door("east", "房门", "west", DOOR_CLOSED);
}
