 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "���춫��");
        set("long", @LONG
һ�˶�ߵ���Ģ��һ��Ƭ������ֲ��ı�Ƥ��Ӳ�������ر�
�Ĵֲڡ�����·�������Ǵ�Ģ���п������ģ�·����Ȼ������
���Կ�������·һ�����˺ܴ�Ĺ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ntdl",
  "south" : __DIR__"dnj",
]));
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-22);
        set("coor/z",-20);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        setup(); 
}  
