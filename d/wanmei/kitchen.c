 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "�����");
        set("long", @LONG
һյ�谵���͵��ڳ¾ɵ���̨�Ϸ��������Ĺ⡣���»��м����뽹��
�ɲ񣬻�����ȼ���š����Ϲ��ڵ�ɽ��Ұ�����������˵���ζ��˿˿����
�ӹ��ڵķ���Ʈ�������˴������Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"backyard",
]));
        set("resource/water",1);
        set("liquid", ([
            "name": "ɽ��Ұ����",
            "container":"���",
            ]) );
        set("coor/x",190);
        set("coor/y",-390);
        set("coor/z",30);
        setup();
}    
