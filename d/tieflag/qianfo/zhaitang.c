 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ի��");
  set("long",@LONG
ի��Ϊ����ɮ�ڳԷ��ĵط�������ͷ®�����񣬴�˵��ɮ������
ע���ۣ�ҹ���μ���ɮ��ͷ®Ȱ����  ի�ã����Ǵ���֮����ի����
��֮��
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang3.c",
            "east" :__DIR__"guanyin.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
  set("coor/x",40);
        set("coor/y",2080);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}     
