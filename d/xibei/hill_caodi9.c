#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","ɽ�²ݵ�");
    set("long",@LONG
����ެ�أ����ܶ�����������Сɽ��ɽ�������������ţ��ɢ����䣬��
��ʤ�����������˶�����ϡ��Źֵ��·���˵����ҲȫȻ��ͨ�����������ˬ
�����ع�����������ɽ�¼䣬˵���嵽�׸����Ķ��߲��ǣ��Ų����ߣ���Ҳ���
�������ڣ���Ҫ�Ǽ��Ÿ�·�������Ҹ��򵼣����Ǹ����̶������߲źá�
LONG);
    set("exits",([
        "north"   : __DIR__"hill_caodi9",
        "west"    : __DIR__"tianchi2",
        "east"    : __DIR__"hill_caodi8",
        "south"   : __DIR__"hill_caodi9",
         
    ]));
    set("objects",([
         __DIR__"npc/goat1": 3,
    ]));
    set("outdoors","xibei");
    setup();
}

