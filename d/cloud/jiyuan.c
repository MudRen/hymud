
// jiyuan.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,3820,0}));
	set("short", "����Ժ");
        set("long",
"��������վ������Ժ�￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "south"  : __DIR__"eroad1", 
                "up"  : __DIR__"jiyuan2",
        ]) );

        set("objects", ([
                __DIR__"npc/mother" : 1,
        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д��������Ժ\n";
}

