//road1.c.����
//date:1997.8.26
//by dan

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"����"NOR);
    set("long",@LONG
��������������Χ����ǹٸ�լ�ڣ���һЩ�ټ��������������������ַǳ���
Զ���ɼ���ڻԻ͵Ĺ���͸��ʵĳ������������Ϸ����ǻʹ��������Ͻ䱸ɭ�ϣ�
�������ǻʼ���������û������ñ�����������������������Ĵ�Ӫ.
LONG);
   
    set("exits",([
        "east"    : __DIR__"bingying1",
        "west"    : __DIR__"bingying2",
        "south"   : __DIR__"road2",
        "north"   : __DIR__"door1",
    ]));  
    set("objects", ([
          __DIR__"npc/bing3" : 1,
    ]) );
    set("outdoors","xingqing");
    setup();
}

