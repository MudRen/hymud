// Room: /d/datong/ylinn2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ջ��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ���
�Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������
¥�µ��ƹ񴦸���Ǯ������˯����
LONG
	);

	set("exits", ([
		"down" : __DIR__"ylinn",
		"east" : __DIR__"ylinn3",
		"north" : __DIR__"ylinn4",
	]));

	setup();
	create_door("east", "����", "west", DOOR_CLOSED);
	create_door("north", "����", "south", DOOR_CLOSED);
}

int valid_leave(object me,string arg)
{
	object room;
	if(arg == "east")
	{
	room = find_object(__DIR__"kezhan3");
	if(!room) return ::valid_leave(me,arg);
	if(room->query_temp("have_person"))
		return notify_fail("���ͷ��������ˡ�\n");
	return ::valid_leave(me,arg);
	}
	if(arg == "north")
	{
	room = find_object(__DIR__"kezhan4");
	if(!room) return ::valid_leave(me,arg);
	if(room->query_temp("have_person"))
		return notify_fail("���ͷ��������ˡ�\n");
	return ::valid_leave(me,arg);
	}

	return ::valid_leave(me,arg);
}