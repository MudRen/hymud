//road10.c.�ݺͷ�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"�ݺͷ�"NOR);
    set("long",@LONG
�����ǻݺͷ�����Χ�����ƽ��סլ����һЩ���̣��������������ַǳ���
�������Ǿ�ƽ������˵�ھ�ƽ���Ǳ߾������ĵ�һƷ���ܶ����ڣ������Ҳ����
��ʿ�����������ж�Ź�¼�������������Ҫ���̣�����ϸ����ΰ������ξ��ӽ�
���������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ���������ȫ������ƽ
����֮һ.
LONG);
   
    set("exits",([
        "east"    : __DIR__"road11",
        "west"    : __DIR__"road9", 
        "south"   : __DIR__"room1",
    ])); 
    set("objects",([
         __DIR__"npc/keshang" : 1,
    ]));
    set("outdoors","xingqing");
    setup();
}

