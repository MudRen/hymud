#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ��Ĳ㣬����ҹĻ�ʹ����ǹ��㣬�����ѩ��Ĵ���\n"
"��������Ծ��˸������Ϊ�����ŵ����һ�еĽ���¥�����ڷ�����ʢ�£�\n"
"�����˼ž�ΰ������¡�\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou5",
          "down": __DIR__"lou3",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/zhouwushu" : 1,
                ])
        );

        setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "up") &&
	    objectp(present("zhou wushu", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
        return ::valid_leave(me, dir);
}