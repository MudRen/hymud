 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����Ҳ��ɮ�û����ã���ɮ��ҹ�ڴ��е���������������ʦ��ʥ
ɮ�񣬴����뷨�ã���������������Ҫ������
LONG
  );
  set("exits",([
            "west":__DIR__"mile.c",
               ]));
        set("objects", ([
                __DIR__"npc/bonze3" : 1,
       ]) );
  set("coor/x",60);
        set("coor/y",2060);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}     
