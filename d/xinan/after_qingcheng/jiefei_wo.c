//written by lnwm on 97/07/08
//jiefei_wo.c

#include <ansi.h>

inherit ROOM;

void create()
{
    set("short","�ٷ���");
    set("long",@LONG
���������ɽ�ٷ˵����ѡ�
LONG);
    set("exits",([
//      "east"   	:		__DIR__ "shan1",
//		"west"		:		__DIR__ "shan2",
    ]));
    setup();
}

