
// zaihuoy.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3850,0}));
	set("short", "�ӻ���");
	set("long",
"��������վ���ӻ����￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
		"north"		: __DIR__"nwroad3",
                "east"          : __DIR__"nroad2" ]) );

	set("objects", ([
                __DIR__"npc/seller" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :)
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����̡�\n";
}

