 //mac's fudong.c
#include <room.h> 
inherit ROOM; 
void create()
{
  set("short","ǧ��");
  set("long",@LONG
ǧ��ɽ��˶������������ϵ����˷��񣬼����ͱ��ϵķ�����
��ǧ�����й����ڷ���Բ�Ϫ���ܺ���ͽֻ�Ե������ܣ����Ҿ�Ѩ
�������Լ�������³���ʱʼ��ľ��ҡ�
LONG
  );
  set("exits",([
         "west" :__DIR__"jinggang.c",
         "north":__DIR__"changlang2.c",
               ]));
          set("objects", ([
                __DIR__"npc/master3" : 1,
       ]) ); 
set("valid_startroom", 1);
  set("coor/x",60);
        set("coor/y",2020);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
} 
