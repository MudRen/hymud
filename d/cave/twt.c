 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long", @LONG
һ���޴���Ҷ�չ������ǰ���Ҷ��Ķ�����ĸߣ�����
һ���������������洹����������ʯҲ�м��ɳ����������
ϸ������Ĳ������������ڵ��¡��ڻ谵�ĵƹ��У�����ʯ
��Ӱ�ӻ�����ȥ������һ�ÿ�С����һ��������粻֪����
ʲô�ط�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"td",
  "south" : __DIR__"qszl",
  "east"  : __DIR__"tdbd",
  "west"  : __DIR__"tsbd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-45);
        set("coor/y",-0);
        set("coor/z",-20);
        setup();
}   
