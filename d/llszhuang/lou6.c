#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ����㣬ҹ��Ϯ�ˣ�������¥����֮�ϣ������ڹ����\n"
"֮�ˣ�Ҳ������Щ�ߴ���ʤ��֮�С�\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou7",
          "down": __DIR__"lou5",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/zhengqimie" : 1,
                ])
        );

        setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "up") &&
	    objectp(present("zheng qimie", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
        return ::valid_leave(me, dir);
}