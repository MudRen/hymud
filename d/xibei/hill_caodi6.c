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
        "north"   : __DIR__"hill_caodi6",
        "west"    : __DIR__"hill_caodi6",
        "east"    : __DIR__"hill_caodi5",
        "south"   : __DIR__"hill_caodi7",
         
    ]));
    set("objects",([
         __DIR__"npc/goat2" :3,
    ]));
    set("outdoors","xibei");
    setup();
}

