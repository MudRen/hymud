
// rich2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2250,3880,0}));
	set("short", "�Ű���Һ�Ժ");
	set("long",
"��������վ���Ű�����￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                 "south" :__DIR__"rich1",
                ]) );

        set("objects", ([
                      __DIR__"npc/chenyaojia":1, 
                      __DIR__"npc/zhang":1, 
                       __DIR__"npc/room_guard":2,
                 ]) );
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д��������Ī�롣\n";
}

