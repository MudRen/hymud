 //mac's dongbei.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��Ϊ̩��������ǵı��ȣ������������Ƹ��ں���������������
��ǲ��ʿ�����浽̩ɽ��������ʱ������˫���������ԧ�챮����
����������ͬ��ʯ�������ɣ������������ڲ���������ͬ�����¡�
LONG
  );
  set("exits",([
         "west":__DIR__"zhengyuan.c",
               ]));
        set("objects", ([
                __DIR__"npc/tian" : 1,
       ]) );
  set("coor/x", 320);
        set("coor/y",2320);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}   
