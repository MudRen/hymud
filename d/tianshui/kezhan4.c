// Room: /d/tianshui/kezhan4.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ���С�Ŀͷ�������ʮ�ּ�ª���ǳ��ɾ�����ǽ����
һ��ľ����ǽ�Ͽ���һ�Ȳ���Ĵ�����
LONG
);
	
	set("sleep_room", 1);
	
	set("hotel",1);

	set("exits", ([
		"south" : __DIR__"kezhan2",
	]));
	setup();
	create_door("south", "����", "north", DOOR_CLOSED);
}
