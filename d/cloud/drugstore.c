
// drugstore.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2100,3920,0}));
	set("short", "ҩ��");
	set("long",
"��������վ��ҩ���￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "south"          : __DIR__"nroad1" ]) );

        set("objects", ([
		__DIR__"npc/doctor" : 1,
	]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д����ҩ��\n";
}

