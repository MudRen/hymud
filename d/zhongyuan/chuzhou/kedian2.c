// �������͵� /d/city/chuzhou/kedian.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

int do_sleep();

void create()
{
    set("short", MAG"���͵��¥"NOR);
    set("long", @LONG
�����ǿ͵�Ķ�¥���徻���ţ�һ���ľ�������СС�������棬����һ��
һ��һ�����Ρ�������ȻС�����Ǻܽྻ���ſڹ������ŵ���������Լ�ɼ��в�
�����ڴ��Ϻ�Ȼ���Ρ����⴫�����ӵ�ߴ�����������˾������ڵļž�������Щ
������ɽ���ġ���ζ����
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "down"      : __DIR__"kedian",
        ]));
    set("sleep_room", "inn");        
    set("objects", ([
    ]));        
    setup();
}

void init()
{
    add_action("do_sleep", "sleep");
}    

int do_sleep()
{
    object me = this_player();
    if( me->query_temp("can_sleep") )
    {
        me->delete_temp("can_sleep");
        return 0;
    }
    message_vision("$N��Ҫ�ϴ�˯����ֻ��С����¥�´�У������ˣ�����Ǯ��˯������\n"
        + "��������Ŀ��˱����ѣ�������̽��ͷ������$N���·��ǿ�ˣ��Ϸ�Ĺ��ܡ�\n", me);
    return 1;
}
            