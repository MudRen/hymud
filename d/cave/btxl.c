 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "������·");
        set("long", @LONG
·�ߵİ����Ѿ����Կ����ˣ����ڱ����ϵͣ������Ȼ��
��һ��СС���ٲ����ٲ�����ˮ�ܼ��������������������ٲ�
���󣬰�����������治���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxm",
  "south" : __DIR__"tzdx",
]));
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-20);
        set("coor/z",-20);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        setup(); 
} 
