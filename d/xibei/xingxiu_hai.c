#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","���޺�");
    set("long",@LONG
���޺���Ϊ��Χ����ˮ���ڶ࣬�������Ϸ���ɢ���˼����������������
�䣬�ݵ������������������ɢ����һ��ǳ������ȴ��ʮ���ɵ�С�ӻ���������
��Χ�ǲ��ɱ���һ������С�ӡ�����ԶԶ�����������ֱ����ʵĴ�ѩɽ��ɽ
���ϱ����ݺᣬ��ѩ������������һ�������
LONG);
    set("exits",([
        "east"    : __DIR__"tianchi1",
        "westup"    : __DIR__"xueshan1",
    ]));
    set("objects",([
         __DIR__"npc/shelu" : 2,
         __DIR__"npc/maoniu0" : 2,
    ]));
    set("outdoors","xibei");
    setup();
}

