
// biaoju.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{

        set("coor",({2200,3780,0}));
       set("my_point","�����");
        set("short", "�ھ�");
        set("long",
"��������վ���ھ��￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "north"          : __DIR__"eroad2" ]) );

        set("objects", ([
                __DIR__"npc/b_header" : 1,
                __DIR__"npc/bfighter" : 1,

        ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����ڡ�\n";
}

