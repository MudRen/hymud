#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
��ľ�������ѱ���ͺ��������ķ������ȼ������о�������˫
�ﳯĵ����ͼ���ľ����Ͻ�������������˻��ɴ�����������
һ����С�
LONG
  );
  set("exits",([
         "north":__DIR__"chanfang2.c",
//         "south":__DIR__"xiangji.c",
         "west" :__DIR__"houyuan.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk" : 1,
       ]) ); 
   
  set("coor/x",60);
        set("coor/y",2090);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}   
