//huanggong.c.�ʹ�
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
         "south"  : __DIR__"door1",
         "north"   : __DIR__"hg2",
//         "east"   : __DIR__"wall1",
    ]));
    set("objects", ([
          __DIR__"npc/bing3" : 4,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("shiwei jun", environment(me))) && 
		dir == "north")
		return notify_fail("һ����������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}    