inherit ROOM;

#include <ansi.h>
void create()
{
  set("short","�������");
  set("long",@LONG
��������ֻ������ģ���ֻ�е���ת�����������ʮ�ֿ��š�
����������ߵĳ��Ӻ��磬���䳵�������Ŀ��š�
LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "east" : __DIR__"qiju",
           "west" : __DIR__"qiju",
           "north" : __DIR__"qiju",
           "south" : __DIR__"qiju",
     ]));
 	set("objects", ([
		__DIR__"npc/qiwushi" : 2,
	]));
     setup();
}
#include "songlin.h"                  