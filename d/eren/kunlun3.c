 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽ��");
        set("long", @LONG
����ǰ�ߣ���·��Ϊ��������������ϡ��������ż�����ܼ������е�������
�����˼�����ɱ֮��������Ҳ�ɶ�ǧ�׼�����������ǧ���ף����¡���ѹ��֮���͡�
һʱ�䣬�ƺ��ӿ���ͻȻ���뵽�϶���ԶԶ��ȥ������������������֮�С�
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yuzhu",
        "east" : __DIR__"kunlun2",
        ]));
        set("objects", ([
                __DIR__"obj/mache": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1010);
        set("coor/y",140);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
