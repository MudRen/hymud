
// tea_corridor.c

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
	set("short", "���������");
	set("long",
"������м��������ᣬ����װ���˲�Ҷ��\n"
);

        set("exits", ([
                "south"          : __DIR__"tearoom",
	]) );

//	set("objects", ([
//	]) );


        setup();

}


