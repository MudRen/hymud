#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ƹ�");
  set("long",@LONG
�����ǳ�����������֮������Ȼ���Ϻ����п��˵�������������Ȼ�Ǵ���������
����Ȼ���˾�����ɨ���ݽ�һ�Ŵ󴲣������̵��������롣��������С���Ϸ���һ��
�������һ�̵��Ļ���һ��С�ڡ�
LONG
  );
        set("exits/south",__DIR__"island");
        set("objects", ([
                __DIR__"npc/qian1" : 1,
                __DIR__"npc/qian2" : 1,
       ]) ); 
    set("resource/water",1);
    set("liquid/name","��ˮ");
    set("liquid/type", "water");
    set("liquid/drunk_apply",6);
  
  set("coor/x",2000);
        set("coor/y",-190);
        set("coor/z",10);
        setup();
 }
                   
