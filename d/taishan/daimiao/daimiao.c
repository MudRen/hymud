 //mac's daimiao.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���");
  set("long",@LONG
����һ������ʯ�����Դ��򱱱����������ֳƶ�����̩ɽ��̩��
��������������̩ɽʱ���д��ĵط���
LONG
  );
  set("exits",([
         "north":__DIR__"zhengyan.c",
         "south":__DIR__"yaocan.c",
               ]));
        set("objects", ([
                __DIR__"npc/yin" : 1,
       ]) ); 
   
        set("coor/x", 310);
        set("coor/y", 2280);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}       
