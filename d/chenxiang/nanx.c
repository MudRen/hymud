 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�ϳ���");
        set("long", @LONG
�������ǻҳ�������������˷�ù��ζ�������˲�������������µ�
������Լ��һ���һ����ӡҲû�У�ֻ����һЩ��ֵ�Բ�ס���ЩԲ��
���ż����ӵ���ǽ��Ȼ��Ͳ����ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxw2",
]));
        set("objects", ([
        __DIR__"npc/yold": 1,
                        ]) );
        set("coor/x",-520);
        set("coor/y",-530);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 