
// park.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	
	set("coor",({2200,3820,0}));
	set("short", "�żһ�԰");
	set("long",
"��������վ���żһ�԰��\n"
);
        set("exits", ([
                "south"          : __DIR__"eroad2" 
        ]) );
        set("objects", ([
                      __DIR__"npc/flower_worker":2,
                   ])); 
        setup();

}

