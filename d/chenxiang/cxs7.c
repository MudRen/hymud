 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "���������");
        set("long", @LONG
�����м��ɸߣ�����ҽ�ʵ�����滹������ͭ����һ��ԭľ���ɵ�
���ſ���ڻ��Ǻ��ϡ���ǽ�������֣����滹��һ�����ļ�¥����¥֮
�仹��ˮͰ��ϸ�Ļ��ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs6",
  "south" : __DIR__"cxs8",
]));
        set("objects", ([
        __DIR__"npc/cg": 2,
                        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-580);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
