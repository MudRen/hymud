 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���춫·");
        set("long", @LONG
ʯ����Ⱥ���е����飬�е��ɵ������еı�������û��һ�롣
���ڵ��³�ʪ��ʯ�����Ѿ�����̦��ʴ�ˣ�����̵�ʲô�Ѿ���
�������һ��С�ľͿ��ܱ�ʯ������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btdm",
  "south" : __DIR__"ztdd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
        set("coor/x",-30);
        set("coor/y",-10);
        set("coor/z",-20);
        setup();
}  
