// ��������� /d/city/chuzhou/longguangge.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"�����"NOR);
    set("long", @LONG
�����λ�ڳ����������һ��С�����ϣ��ͳ���������ͨ��ң���Ӧ����ӳ
��Ȥ��������㣬���ܸ����������ֲ��ľ��Ҳ�ǳ���ʿ�����ж�ȥ��һ��ȥ����
������Ȼ���ߣ���������ռ�˵��������ԵǸ�ƾ��һ���������ܿ�����಻��
�ľ��µġ�
LONG
    );
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "west"      : __DIR__"nan_men",
        "up"        : __DIR__"longguangge2",
    ]));
    set("objects", ([
    ]));
    setup();
}
