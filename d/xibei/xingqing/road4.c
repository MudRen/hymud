//road4.c.���Ĺ㳡
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"���Ĺ㳡"NOR);
    set("long",@LONG
���������츮�����ģ��������������Ƕ����˹���ƽʱ���ַǷ�����������
���Ļʹ�������Ҫ�����ˣ��Ե��������塣��������ΰ������ξ��ӽ���������
�̵��̲飬�Է���ϸ�����룬ǧ����������ǡ���������������ǵ������Ĵ�
�֣����и�̨�£�����Ԫ껹�����Ϊ��ҵ�����������ǻʳ���.
LONG);
   
    set("exits",([
        "north"   : __DIR__"road3",
        "south"   : __DIR__"road5",
        "east"    : __DIR__"road7",
        "west"    : __DIR__"road14",
    ]));
    set("objects",([
            __DIR__"npc/bing2"   : 2,
            __DIR__"npc/keshang" : 1,
    ]));
    set("outdoors","xingqing");
    setup();
}

