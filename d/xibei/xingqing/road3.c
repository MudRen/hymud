//road3.c.����
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
�������ǻʼ���������û������ñ��������������ֱ��ǹ���Ժ����˼Ժ��
LONG);
   
    set("exits",([
        "east"    : __DIR__"yuan1",
        "west"    : __DIR__"yuan2",
        "south"   : __DIR__"road4",
        "north"   : __DIR__"road2",
    ]));  
    set("objects", ([
          __DIR__"npc/bing3" : 1,
    ]) );
    set("outdoors","xingqing");
    setup();
}

