#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",BLU "����"NOR);
  set("long",@LONG
���о���һ����ˮ�أ���ˮ���壬����������͸�������յ���ˮ�ϣ��ٵ�ӳ����
�����ϣ�����С�Ҷ����ڲ���֮�С���ˮ���м�ͷ�������е��ζ���һ������������
��Ů������˼�����ڳرߡ�
LONG
  );
        set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/blugirl" : 1,
       ]) );
  
  set("coor/x",70);
        set("coor/y",0);
        set("coor/z",-30);
        setup();
  replace_program(ROOM);
}  
