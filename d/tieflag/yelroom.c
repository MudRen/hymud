#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL "����"NOR);
  set("long",@LONG
����һ��������Σ����̣������������趼���ý�ֽ�������ģ��������ıڶ�
���Ž�ֽ�����˲��ɵ�����ֽ�������仰����
LONG
  );
        set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/yelgirl" : 1,
       ]) );
  
  set("coor/x",70);
        set("coor/y",10);
        set("coor/z",-30);
        setup();
  replace_program(ROOM);
 } 
