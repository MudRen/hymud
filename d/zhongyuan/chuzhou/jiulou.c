// ������¥ /d/city/chuzhou/jiulou.c
// by lala, 1997-12-04
inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", MAG"��¥"NOR);
    set("long", @LONG
����ȫ���ݳ����Ҳ���������ľ�¥��ԭ���������򽭶�ͳ˾��¥���ģ���
���ĳ����ڵ����֣����С����廴ˮ��֮�⡣���۳�һ����ʮ�壬�����������
�Ǻ��Ĳ��С���Ҿ�¥��Ķ��ǳ��ݳ���һ���ĳ��ӣ��������صķ�ζ�ˣ���
Ȼ���Ի������Ϊ������������㣬��ζ����������Ĳ�ʵΪ����һ�����ܡ�
    ��¥�ش����ݳǵ����ģ���Χ�ǳ����ĸ��г��е����������С����кͶ�
�С���Ϊ���ݳǵĽ�ͨҪ������¥��Χ��ӵ�����ֲ�����
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou");
    set("exits", ([
        "west"      : __DIR__"xishi",
        "northeast" : __DIR__"beishi",
        "southeast" : __DIR__"dongshi",
        "up"        : __DIR__"jiulou2",
        ]));
    set("objects", ([
        __DIR__"npc/zuihan" :   1,
    ]));        
    setup();
}
