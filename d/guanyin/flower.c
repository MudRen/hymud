 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ҳ��֪��ã�����ͻȻ����һ�������۵Ļ��㡣�⻨�㲻��ĵ
��������õ�壬Ҳ����÷�����Ǿ�......�⻨�����۵þ����������С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sand",
  "north" : __DIR__"valley",
])); 
        set("outdoors", "fengyun");
        set("coor/x",-1090);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
