 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "һƷ��");
        set("long", @LONG
һƷ���Ǹ��ܴ�Ĳ�ݣ������ͨ�����и�ʽ�������ˣ�Խ��Ĳ������Խ�ࡣ
�������ǲ���������е�ʱ������Ŀ���ȴ���ܶ࣬��������ģ�һ���������ģ�
һ�����У�һ�����ӣ�һ����������ͷ������һ���Ƿ������ϴ��˯�Ĵ����ӡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet2",
        ]));
        set("objects", ([
        __DIR__"npc/gwaiter":     1,
                
        ]) );
        set("coor/x",-1115);
        set("coor/y",200);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
