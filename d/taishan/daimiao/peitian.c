//mac's peitan.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�������ĵ�һ�����ţ���������ϵĶ����������ʣ������š�
��������һ��Ժ����ԺΪ����Ժ����ԺΪ�껨��Ժ��
LONG
  );
  set("exits",([
         "north":__DIR__"renan.c",
         "south":__DIR__"zhengyan.c",
         "east" :__DIR__"hanbai.c",
         "west" :__DIR__"yuhua.c",
               ]));
          set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2300);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
} 
