// Room: /d/datong/ylinn4.c

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
		"south" : __DIR__"ylinn2",
	]));
	setup();
	create_door("south", "����", "north", DOOR_CLOSED);
}

void init()
{
	object me = this_player();
	if(!wizardp(me))
	{
		add_action("do_leave","quit");
		set_temp("have_person",1);
	}
	return;
}

int do_leave(string arg)
{
	delete_temp("have_person");
	return 0;
}

int valid_leave(object me,string arg)
{
	delete_temp("have_person");
	return ::valid_leave(me,arg);
}
