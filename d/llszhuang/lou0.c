#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�� �� ¥"NOR);
        set("long",
"ǰ����һ��������ʮ���ɣ���������ľ�ԲԵ�Сƽ��ɽ�ϾŲ�ĸ�¥\n"
"����̨����Ե�е�̾�ϸ�ĺ�Ҷ��ƿʯ���ˣ���Χ���ȣ��븽����ɽׯ¥\n"
"̨����������ٲȻһ�塣��Щ¥��̨ͤ��ģ�����������������γ���һ��\n"
"�Ӵ�Ľ����顣�˴����ڣ�������ʧ�˸��˵���С�о���\n"
);

        set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"dynamic/jiuqu9",
          "enter": __DIR__"lou1",
          "west": __DIR__"shishi",
        ]));
        set("no_magic", "1");

        set("objects", ([
                        __DIR__"npc/zhaoyishang" : 1,
                ])
        );

        setup();
}

int valid_leave(object me, string dir)
{
	object obj;
	if ((dir == "enter") &&
	    objectp(present("zhao yishang", environment(me))))
	{
		return notify_fail("�и�����ס���㡣\n");
	}
        return ::valid_leave(me, dir);
}
