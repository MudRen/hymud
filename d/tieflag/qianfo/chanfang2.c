#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����һ���徻���ŵ�С�ݣ����������������еĵط���ǽ
������������Ļ�����������Ϊ��һ���Ħ������ۿɣ�����ɮ貣�
������ţ�������̣�������ܣ�͸���������Կ�����ǰ��÷����
LONG
  );
  set("exits",([
         "south":__DIR__"changlang4.c",
         "northwest":__DIR__"houshan.c",
         "west" :__DIR__"yezhang.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk" : 1,
       ]) );
   
  set("coor/x",60);
        set("coor/y",2100);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
} 
