// ������ͨ�� /d/city/chuzhou/wentongta.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"��ͨ��"NOR);
    set("long", @LONG
��ͨ��λ�ڳ��������׺�֮������Ƕ��ϵ������ң����š���׳�ķ塱��
�ʵ�����ͨ����ȫ���ߴ�ʮ���㣬��˵���������Կ����������ݱ�����Ǻ�һֱ
���ɿڵĴ�·��ȫ����⣬���Ǹ�ƾ��Զ���ĺõط���
LONG
    );
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "southeast" : __DIR__"tianbao_lu",
        "up"        : __DIR__"wentongta2",
    ]));
    set("objects", ([
        __DIR__"npc/youke"  :   3,
    ]));
    setup();
}

int valid_leave( object me, string dir )
{
    if( me->query("no_leave_chuzhou")
    && dir == "up" )
        return notify_fail("�����ڲ����뿪���ݡ�\n");
    return ::valid_leave( me, dir );
}
