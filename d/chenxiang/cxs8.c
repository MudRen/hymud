 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���С·");
        set("long", @LONG
�����ǳ�������ţ������������Ե���ܶ�Ӣ�ۺú�������
�������߾���Ҳû�л����ˡ����������ո�ǿ�����Ҫ������
���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs7",
  "south" : "/d/zhaoze/edge",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-590);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
