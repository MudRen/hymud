 //mac's tongting.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ͭͤ����");
  set("long",@LONG
��ǰ��������һ�������ɵ�ͭ��ͤ�ӣ�ͤ��Ϊһʵ������������
�����������ƣ�ɽˮ��ʯ��Ԣ��������գ����������ɽ���곤����
˼��
LONG
  );
  set("exits",([
         "north":__DIR__"houzai.c",
         "south":__DIR__"houqing.c",
               ]));
        set("objects", ([
                __DIR__"obj/ding_dm" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2350);
        set("coor/z",0);
        setup();
//  replace_program(ROOM);
}    
void init()
{
        add_action("do_climb","climb");
}
int do_climb()
{
        object me,room;
        me = this_player();
        message_vision("$N�ֽŲ��ã�����ͤ��ͤ����������ͤ����\n",me);
        room = load_object(__DIR__"ttop");
        me->move(room);
        return 1;        
} 