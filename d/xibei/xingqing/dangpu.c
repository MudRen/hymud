//dangpu.c.����
//date:1997.8.28
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"���쵱��"NOR);
        set("long", @LONG
�������ֺŵ��̣�����������棬д�š����쵱�̡��ĸ����ֵĺ��ң�����
�߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���̨��ĳ���ͷҲ��̧��ֻ�˲�������
�̣���̨�Ϸ�����һ�����ӣ����飺������Ը���Ų���Ƿ�����������Ŀ�����Ҫ
Ǯ��ת���Ǯ������������
LONG
        );
    set("exits", ([ 
                "east"  : __DIR__"road5",
        ]));
        set("dangpu_location","xingqing");

        set("objects",([
                __DIR__"npc/chaofeng" : 1,
                ]) );
        setup();
}                       


