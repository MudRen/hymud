// Room: /huanghe/huanghe7.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���
������ȥ��ʹ������������ˮʱ�Ŀ�����
LONG );
	set("exits", ([
		"northeast" : __DIR__"huanghe8",
		"northwest" : __DIR__"yyd/damen",
		"southwest" : __DIR__"huanghe6",
	]));
        set("objects", ([
                __DIR__"yyd/npc/zhou" : 1,
        ]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("zhou weixing", environment(me))) && 
		dir == "northwest")
		return notify_fail("��������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
