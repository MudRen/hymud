
// tea_corridor.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({1890,3900,0}));
	set("short", "��Ժǰ��");
	set("long",
"������������Ժ��ǰ�����򵥵ĳ�����͸��һ����󲻷������ɡ�һ�ź������İ�������\n"
"���ڴ������룬��ֻ��ڵ�̫ʦ�������������ӵ����ԡ�\n"
);

        set("exits", ([
                "east"          : __DIR__"god1",
	]) );

	set("objects", ([
//    __DIR__"npc/god" : 1,
    ]) );

        setup();

}


