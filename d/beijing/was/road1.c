#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
������һ�����ѵ�С·�ϡ��ϱ߷���һ��С�߸ڿ��Իص����ǡ�
LONG );
        set("exits", ([
                "east" : __DIR__"road2",
        "south" : "/d/heimuya/road3",
        ]));

        set("outdoors", "beijing");
        setup();
}
