#include <room.h>
inherit ROOM;
void create()
{
  set("short","Ү����");
  set("long",@LONG
��ӵ������֮���Ϊ�������ɵľ������˹����������ڵĵմ���
��ʼ������������������ĵ�����ӣ��˺��˲ű���������һ
��С�ţ�û�з��ɵ������κ��˲������롣
LONG
  );
  set("exits",([
         "south":__DIR__"houyuan.c",
         "north":__DIR__"mishi1.c",
         "east" :__DIR__"chanfang2.c",
         "west" :__DIR__"chanfang.c"
               ]));
          set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
        set("valid_startroom", 1);
//      create_door("north","ʯ��","south",DOOR_CLOSED);
        set("coor/x",50);
        set("coor/y",2100);
        set("coor/z",30);
        setup();
}     
