 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","Τ�Ե�");
  set("long",@LONG
Τ������Ϊ���������°˽�֮һ�����������ƣ��ֽ������ػ�
٤����Ϊ���µ��ػ���˫�ֺ�ʮ���ᱦ������������ƽ����ע��
�������ˡ�
LONG
  );
  set("exits",([
            "south" :__DIR__"mile.c",
            "north" :__DIR__"guanyin.c",
            "westup":__DIR__"zhonggu.c",
            "eastup":__DIR__"zhonggu2.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze5" : 1,
       ]) );
  set("coor/x",50);
        set("coor/y",2070);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
} 
