 //mac's hanbai.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","����Ժ");
  set("long",@LONG
��ôִ������֦�ϲԾ��ĹŰ�����Ժ�У�Ϊ�������Ԫ��Ԫ��
����̩ɽʱ��ֲ��
LONG
  );
  set("exits",([
         "west":__DIR__"peitian.c",
               ]));
          set("objects", ([
                __DIR__"npc/ren" : 1,
       ]) );
  set("coor/x",320);
        set("coor/y",2300);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}      
