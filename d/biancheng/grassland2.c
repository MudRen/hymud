 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���");
        set("long", @LONG
ǰ��һƬ�ƻ������õ�ӭ��������Ȼ���ڵƻ�Իʹ�����������������˻֮
����������˷����˹�������Ŀ�Ĺˣ�ֻ���ò���㣬��������������Ǿִٳ�
���е�����������ԶԶ����ȥ��һ���ɫ�Ĵ������ڷ�ɳ�зɾ�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"grassland1a",
                "north" : __DIR__"gate",
                "northeast": __DIR__"grassland3",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1110);
        set("coor/y",250);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
