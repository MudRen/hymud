#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
��ɴ�й��߻����������뵣�һλ������ϥ��������֮�ϡ����ű���һ��¯����
�ƴ���¯��ȽȽ���𣬳������������䡣 
LONG
  );
        set("exits/out" ,__DIR__"outboat");
    set("objects",([
        __DIR__"npc/jiayi" : 1,
        __DIR__"obj/coffin": 1,
    ]) ); 
    set("coor/x",100);
        set("coor/y",40);
        set("coor/z",-30);
        setup();
        replace_program(ROOM);
 }     
