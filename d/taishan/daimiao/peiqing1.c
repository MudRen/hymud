 //mac's peiqing1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���޵�");
  set("long",@LONG
��Ϊ̩ɽ���������ס������������һ�Ŵ�����̴͸����̵���
齣���ϵ��������б����ж������˯��˯��Ϊ̴ľ��̣������
��������������
LONG
  );
  set("exits",([
         "west":__DIR__"houqing.c",
               ]));
        set("objects", ([
        __DIR__"obj/huabei" : 1,
        __DIR__"obj/shenji" : 1,
        __DIR__"npc/xintu" : 1,
                        ]) );
          set("coor/x",320);
        set("coor/y",2340);
        set("coor/z",0);
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("huabei", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        item = new(__DIR__"obj/xiang");
        item->move(con);
        }
}  
