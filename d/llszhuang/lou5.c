#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"���ǽ���¥�ĵ���㣬���Ѿ��������������󼰵ĸ߶ȣ��Ӵ�������\n"
"��ȥ��Զ����ҵƻ��뷱�����ԣ�����ɽׯ���ȴ��һƬ��ڣ���ʱ��\n"
"��������������\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou6",
          "down": __DIR__"lou4",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/wuliupo" : 1,
                ])
        );
       setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "up") &&
	    objectp(present("wu liupo", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
        return ::valid_leave(me, dir);
}