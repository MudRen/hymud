 //mac's jiaolou1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","����¥");
  set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥��
��һ��󱮣�������һ���֣�
                                ��
LONG
  );
  set("exits",([
         "north":__DIR__"jiaolou3.c",
         "east" :__DIR__"zhengyan.c",
               ]));
   
        set("objects", ([
                __DIR__"npc/gang1" : 1,
                __DIR__"npc/wolfdog" : 1,
       ]) );
        set("coor/x",300);
        set("coor/y",2290);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}       
