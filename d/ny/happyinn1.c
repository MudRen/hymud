// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("coor",({0,4950,10}));
	set("short", "�ɶ�Ҫ��");
        set("long",
"����վ��һ��Ҫ��ǰ���ճ���������һ��С�����������ΰ�ʣ���������ڳԷ���С��\n"
"������һ�����죬��д������������ ��·��������Щ�߾����佫��Ϣ�����������ּ�С·����\n"
"�����뿪��Զ���ˡ�\n"
);
        set("exits", ([ /* sizeof() = 3 */
        "north" : __DIR__"droad0",
        "west" : __DIR__"happyinn0",
       "south" : __DIR__"crossroad",
]));
        set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/room_waiter" : 2,
]));
        set("outdoors", "ny");
        setup();
        replace_program(ROOM);
}

