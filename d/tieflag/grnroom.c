#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",GRN "����"NOR);
  set("long",@LONG
һ���ݣ����Ȼ�����Ҳ���һ���½ŵĵط������������˸�ʽ�����Ļ��ݣ�����
�󲿷��㶼�в��������֡�������Щ�������εĲ�ľ���㶼�̲�ס��Ҫ����һ����
�ǡ�
LONG
  );
        set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/grngirl" : 1,
       ]) );
  
  set("coor/x",90);
        set("coor/y",10);
        set("coor/z",-30);
        setup();
  replace_program(ROOM);
 }      
