
// woodboxy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({1950,3900,0}));
	set("short", "�ײ���");
	set("long",
"��������վ�ڹײ����￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "east"          : __DIR__"nwroad2",
                "west"          : __DIR__"god1"
                      ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
                __DIR__"npc/box_boss" : 1,
        __DIR__"npc/box_waiter" : 1,
 ]) );
        setup();

}

string look_sign(object me)
{
        return "����д�����ס�\n";
}

