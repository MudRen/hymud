// Room: /d/lumaji/kezhan2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ջ��¥");
	set("long", @LONG
�����ǿ͵�Ķ�¥�������������Ա߿ͷ��ﲻʱ�غ����Ĵ�
������һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ���������
LONG
	);

	set("exits", ([
		"down" : __DIR__"kezhan",
		"east" : __DIR__"kezhan3",
	]));

	setup();
	
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
	return ::valid_leave(me,arg);
}