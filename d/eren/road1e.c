 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��·");
        set("long", @long
��Զ�����ǰ���ɽׯ��ɽɫ��䣬����ɫ�Ĳݵ��ϣ�һ�������ɫ���ݶ���̫
�������Ź⡣��������ʯ������ԣ��������˹Ű����ɡ���ʱ����һ��������ڵ�
������Ȼ����ׯ�������ı��͡�
long

        );
        set("exits", ([ 
                "east" : __DIR__"road1d",
                "north": __DIR__"yuanvillage",
        ]));
        set("objects", ([
                __DIR__"obj/grass": 1,
        ]) );
        set("outdoors", "eren");
set("coor/x",-1090);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        //replace_program(ROOM);
}   
