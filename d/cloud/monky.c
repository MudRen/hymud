
// monky.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3780,0}));
	set("short", "իԺ");
	set("long",
"��������վ��իԺ�￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "north"          : __DIR__"wroad2" ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("objects", ([
		__DIR__"npc/monk" : 1,

	]) );

        setup();

}

string look_sign(object me)
{
        return "����д�����ơ�\n";
}

