 //mac's zhengyan
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
����һ�����͵ĵ��۴��ţ����ɸߵ���שΧǽ��������������
���ߴ��ʵ���������������Ȼ�𾴣�С�ݵ��һ����ң�
�����š�  ������������š�
LONG
  );
  set("exits",([
         "north":__DIR__"peitian.c",
         "south":__DIR__"daimiao.c",
         "west" :__DIR__"jiaolou1.c",
         "east" :__DIR__"jiaolou2.c",
               ]));
        set("objects", ([
                __DIR__"npc/tong" : 1,
       ]) );
        set("coor/x",310);
        set("coor/y",2290);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}   
