 //mac's tiankuang.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ܵ�");
  set("long",@LONG
���ܵ�Ϊ�������Ϊ�ߴ�Ķ�����۲�������Χ�ڷ�������
�ʵ۾��м���ʱ�õļ�������������ڶ���������Ϊ���ͱڻ���չʾ
̩ɽ���Ѳʱ�ĺƴ��档
LONG
  );
  set("exits",([
         "north":__DIR__"houqing.c",
         "south":__DIR__"zhengyuan.c",
               ]));
        set("objects", ([
                __DIR__"npc/xi" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2330);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}  
