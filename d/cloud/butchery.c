
// butchery.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({1950,3950,0}));
	set("short", "������");
	set("long",
"��������վ�������������Ϲ�����Ѫ���ܵ����⣬һ�����������������ʱ�м�ֻ��\n"
"Ӭ�����������ȥ�������ſڵĵط���һ��ţ�ǵ�ɵ�����(sign)������д��Щʲô��\n"
);

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([
                "east"          : __DIR__"nwroad1" ]) );

        set("objects", ([
                __DIR__"npc/butcher" : 1,
		__DIR__"npc/fly.c" : 2,
 ]) );

        setup();

}

string look_sign(object me)
{
        return (@LONG
���꼴���չ�������
LONG);
}

