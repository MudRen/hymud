 //mac's renan.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�ʰ���");
  set("long",@LONG
�������ĵڶ������ţ�������ű���Կ������հ�������ܵ�
��Զ����ΰ��̩ɽ�ĳ���֮�£��Ե�����׳�ۡ�
LONG
  );
  set("exits",([
         "north":__DIR__"zhengyuan.c",
         "south":__DIR__"peitian.c",
         "east" :__DIR__"dongyu.c",
         "west" :__DIR__"chuxun.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2310);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}    
