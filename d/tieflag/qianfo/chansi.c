 //mac's chansi.c
#include <room.h> 
inherit ROOM; 
void create()
{
  set("short","�˹�����");
  set("long",@LONG
��ʯ�����ɽ���Ͽ��ţ��˹����¡�����Ʈ��������������һ
�����µĸо���ɽ�����ԵĶ�����������עĿ��
                ĺ      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                ��      ��
                �ͣ�    �ˡ�    
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
                                __DIR__"npc/greeting" : 2,
       ]) );
  set("exits",([
         "southdown":__DIR__"fudi.c",
         "north"    :__DIR__"jinggang.c"
               ]));
   
          set("outdoors", "qianfo");
        set("coor/x",50);
        set("coor/y",2010);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}    
