 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������Ȼ�ոճ��߹�ģ�������еĶ��Ѿ����ˡ�������Ȼֻ��
װ�����ã������������ש���ټ���һ����̵���̦��ż������С��
������ڴ�פ�㡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs2",
  "west" : __DIR__"mw",
  "east" : __DIR__"me",
  "south" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
