#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������¥����");
        set("long", @LONG
������������¥�Ĵ������൱�Ŀ���һ��������Ů�������ã���Ů
ǰ����һ��޴�ĺ�ľ�������ܣ�����վ�����ױ����ų��������ɡ�
LONG );
        set("exits", ([ 
                "down" : __DIR__"was_lou3",
        ]));
        set("objects", ([
                __DIR__"npc/ada" : 1,
                __DIR__"npc/aer" : 1,
                __DIR__"npc/asan" : 1,
                __DIR__"npc/he" : 1,
                __DIR__"npc/zhao" : 1,
                __DIR__"obj/shelf" : 1,
        ]) );

        setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "down") &&
	    objectp(present("luzhang ke", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
	
	if ((dir == "down") &&
	    objectp(present("hebi weng", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
	
        return ::valid_leave(me, dir);
}