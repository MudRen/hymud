//road2.c.����
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
�������ǻʼ���������û������ñ��������������ֱ��Ǿ�֯Ժ�ͽ�Ժ.
LONG);
   
    set("exits",([
        "east"    : __DIR__"yuan3",
        "west"    : __DIR__"yuan4",
        "south"   : __DIR__"road3",
        "north"   : __DIR__"road1",
    ]));  
    set("objects", ([
          __DIR__"npc/bing3" : 1,
    ]) );
    set("outdoors","xingqing");
    setup();
}

