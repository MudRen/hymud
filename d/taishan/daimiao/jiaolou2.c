 //mac's jiaolou1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","Ǭ��¥");
  set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥��
��һ��󱮣�������һ���֣�
                                Ǭ
LONG
  );
  set("exits",([
         "north":__DIR__"jiaolou4.c",
         "west" :__DIR__"zhengyan.c",
               ]));
          set("objects", ([
                __DIR__"npc/gang2" : 1,
                  __DIR__"npc/wolfdog" : 1,
       ]) );
  set("coor/x",320);
        set("coor/y",2290);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}
