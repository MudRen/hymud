 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��Ū��");
        set("long", @LONG
͸����÷�ù���������ƫ������ϡ���Կ������ڵľ�������
�İ��̴������ķ�϶�������漴��΢΢ɽ�紵ɢ���������ó�����
����Ʈ��֮�С� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"frontyard",
  "northeast" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/cat": 1,
        __DIR__"npc/ass" : 2,
                        ]) );
        set("coor/x",160);
        set("coor/y",-410);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}      
