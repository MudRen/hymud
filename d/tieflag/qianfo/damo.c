 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ħ��");
  set("long",@LONG
�����ĦΪ�й����ڵ�ʼ�棬����ɽ�����´��ڹ������ţ�����
����Ϊ����֮�棬������ʦ�����ֳ����Ρ����﹩�����������λ��
ɽ���ޡ�
LONG
  );
  set("exits",([
         "west":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                __DIR__"obj/damo" : 1,
       ]) );
  set("coor/x",60);
        set("coor/y",2050);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}    
