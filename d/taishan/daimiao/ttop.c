 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "ͤ��");
        set("long", @LONG
ͤ����������ͭ�⣬�ǳ����š�һ��������վ�ڶ��⴦�������
��Զ���������·�������һ��ϸϸ�Ļ�ɳ���ƺ����˺�Զ��·������

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"tongting",
]));
        set("outdoors", "daimiao");
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("coor/x",310);
        set("coor/y",2350);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
