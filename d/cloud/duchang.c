
// duchang.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,3780,0}));
	set("short", "�ĳ�");
	set("long",
"��������վ�ڶĳ��￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "north"          : __DIR__"eroad1", 
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

	set("objects", ([
		__DIR__"npc/judge" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "�ģ�ʤ��Ӯ˫��\n";
}

