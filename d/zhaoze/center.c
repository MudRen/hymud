 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ̶��ˮ��ͣ��ð�����ݣ���֦��Ҷ��ͬ���Ƶİ׹����гߺ�
���鰵��ɫ��������ʯ���ں�ˮ���룬���沼���˸���ʬ����̶ˮ
��Ư���Ŷζο�ľ����Щ��ɢ�����������̡�
LONG
        );
        set("exits", ([ 
                 "west" : __DIR__"zhaoze4",
]));
        set("objects", ([
                __DIR__"npc/dragon" : 1,
       ]) );
        set("outdoors", "zhaoze");
//      set("no_curse",1);
        set("coor/x",-520);
        set("coor/y",-650);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}  
