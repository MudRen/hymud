
// rich.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2250,3870,0}));
	set("short", "�Ű��������");
	set("long",
"��������վ���Ű���������￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([/* sizeof()== 2 */
              "south" : __DIR__"rich", 
                 "north" :__DIR__"rich2",
                ]) );

        set("objects", ([
                 __DIR__"npc/dashou":2,
                __DIR__"npc/dashou_head":1,  
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

