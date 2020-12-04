
// rich.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({2250,3860,0}));
	set("short", "�Ű����ǰ��");
	set("long",
"��������վ���Ű�����￿���ſڵĵط���һ����ľ��ɵ�����(sign)��\n"
);
        set("exits", ([
                "south"          : __DIR__"eroad3", 

                 "north" :__DIR__"rich1",
                ]));
        set("outdoors","cloud");
        set("objects", ([
                 __DIR__"npc/room_waiter":2,
                 __DIR__"npc/whitelady":3,
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
int valid_leave(object me, string dir)
{
	if ( objectp(present("white lady", environment(me))) && 
		dir == "north")
		return notify_fail("���½�����ס�����ȥ·��˵��: �����˷Ը��� ���˲������ڡ�\n");
	return ::valid_leave(me, dir);
}


