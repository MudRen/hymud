#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����һ���徻���ŵ�С�ݣ����������������еĵط���ǽ
������������Ļ�����������Ϊ��һ���Ħ������ۿɣ�����
ɮ貣�������ţ�������̣�������ܣ�͸���������Կ�����ǰ��÷����
LONG
  );
  set("exits",([
         "northeast":__DIR__"houshan.c",
         "south":__DIR__"changlang3.c",
         "east" : __DIR__"yezhang.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk" : 5,
       ]) );
  set("coor/x",40);
        set("coor/y",2100);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}      
