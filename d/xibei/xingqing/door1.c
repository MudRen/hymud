//door1.c.�ʹ�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"�ʹ�"NOR);
    set("long",@LONG
��ǰ�����Ļʹ�������ʡ������Ժ����˾������������������ڹ����ڡ���
���ʹ���Ԫ껹�����һƬ����ڻԻ͵Ĺ����Ⱥ��ƽ���ס�ĵͰ������γ���
���Աȡ����Źرգ����������أ��䱸ɭ�ϡ�
LONG);
    set("exits",([
         "south"  : __DIR__"road1",
         "north"  : __DIR__"huanggong",
         "west"   : __DIR__"wall7",
         "east"   : __DIR__"wall1",
    ]));
    set("objects", ([
          __DIR__"npc/bing3" : 3,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

