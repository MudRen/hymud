 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�����ֵ���ʾ�Ž���С�����ֶ��ؽ��еķ��԰���ε�С�ź��
һ�������С���������µ���ˮ����ƼȾ�ɰ��˵Ĵ��̡�ż��һ��ֻ����
�����������źӱߵ���ź��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx3",
  "south" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-490);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
