#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ȵ�");
        set("long", @LONG
��һ�߽�����о����ռ���������һ��С����
��ɿ�����ֱ�����ߵ��ȵ�����ֱ�������죬����
��������⡣
LONG );
        set("objects", ([
                 ]));

               set("exits", ([
                "north"  : __DIR__"jingduan",
                                
        ]));

//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

