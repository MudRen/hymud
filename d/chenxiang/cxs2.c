 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�������·");
        set("long", @LONG
���������̨�ܽ��������Կ������ֵ�Ӱ�ӡ����ܶ���ո�µģ�
һ�����Ǹոտ��������ĵط����������ϳ��������������½�����
���õĵش���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter1",
  "west" : __DIR__"ch",
  "east" : __DIR__"cag",
  "south" : __DIR__"cxs3",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-530);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
