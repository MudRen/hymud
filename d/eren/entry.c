 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
        set("short","ʯ��");
        set("long","һ�ºܸߵ�ʯ�ڣ������������٣�ʯ������һ��С�š�\n");
        set("exits",([
//               "south":__DIR__"qianyuan.c",
               ]));
        set("objects", ([
                __DIR__"obj/stonedoor" : 1,
/*              __DIR__"obj/heart":1,
                __DIR__"obj/liver":1,
                __DIR__"obj/stomach":1,
                __DIR__"obj/lung":1,
                __DIR__"obj/kidney":1,*/
        ]) );
        set("item_desc", ([
                "mark": "���ƺ����Խ���������ӡ���루�������裩ͭ�����ڡ�\n",
                "��ӡ" : "���ƺ����Խ���������ӡ���루�������裩ͭ�����ڡ�\n", 
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
