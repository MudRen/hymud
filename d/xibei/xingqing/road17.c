//road17.c.˳�ɷ�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"˳�ɷ�"NOR);
    set("long",@LONG
������˳�ɷ�����Χ�����ƽ��סլ����һЩ���̣��������������ַǳ���
Զ���ɼ���ڻԻ͵Ĺ���͸��ʵĳ���������������Ҫ���̣�����ϸ����ΰ���
���ξ��ӽ����������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ��������ƽ
���������ڳ�����ս���������ĵİ�������ܿ�.....
LONG);
   
    set("exits",([
        "south"   : __DIR__"room2",
        "east"    : __DIR__"road16",
        "west"    : __DIR__"road18",
    ]));
    set("objects",([
         __DIR__"npc/keshang" : 1,
    ]));
    set("outdoors","xingqing");
    setup();
}

