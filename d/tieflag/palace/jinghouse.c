#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
С������ľ��ᣬ�����ڴ���֮�䡣ѩ�׵�ǽ�ڳ��������̣�����һ����
���ĸо�������Ѿ�������ڷ������塣���еĲ�����Ȼ�򵥣�ȴ�쳣�ľ��¡�
΢��͸��ɴ�����촵���������������㡣
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bookhouse",
  "west" : __DIR__"bamboo",
]));
        set("objects", ([
        __DIR__"npc/playinggirl" : 8,
                        ]) ); 
        set("coor/x",300);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
        replace_program(ROOM); 
}    
