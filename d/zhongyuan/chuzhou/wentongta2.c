// ������ͨ���ڲ� /d/city/chuzhou/wentongta2.c
// by lala, 1997-12-05

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"��ͨ��"NOR);
    set("long", @LONG
��ͨ��������ľ�ƽṹ������ľ�Ƶ�¥���ϣ�ֻ����¥��֨�����죬һЩ��
��������������������һ��б������������з��衣������ܰ���ֻ�ܿ�������
��Լ�ǹ�������Ħ������񡣾�˵վ��������߲���Կ������ݳǱ���һֱ����
�Ӷɿڵķ�⡣
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("exits", ([
        "up"        : __FILE__,
        "down"      : __FILE__
    ]));
    set("objects", ([
    ]));
    setup();
}

int valid_leave(object me, string dir)
{
    if( dir == "up" )
    {
        if( me->query_temp("wentongta") > 10 )
        {
            me->move(__DIR__"wentongta3");
            me->add_temp("wentongta", 1);
            return notify_fail("");
        }
        me->add_temp("wentongta", 1);
    }                               
    if( dir == "down" )
    {
        if( me->query_temp("wentongta") < 1 )
        {
            me->move(__DIR__"wentongta");
            me->add_temp("wentongta", -1);
            return notify_fail("");
        }
        me->add_temp("wentongta", -1);
    }        
    return ::valid_leave(me, dir);
}
    