 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���ׯ");
        set("long", @LONG
�´��ĵĳ��ׯ�����󣬵������ֵط����Ѿ��������Ǻ��������ˡ����߿��
��̨�϶�����һƥƥ���޵ĳ�С�һ�����ֳɵ��·����������������ȴ�Ե�û��
��ɵ����ӣ�ֻϣ�����ڣ������ڵ�����Ȼ�ǻ�ƣ��ڼ���ȴ���ϰ塣�󷿵���
�����ţ��������Ű�͸����������������������龰��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet1",
                "south": __DIR__"road3",
                "north": __DIR__"silkshop2",
        ]));
        set("objects", ([
                __DIR__"npc/huoji":     1,
                __DIR__"npc/pregnant_woman": 1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",190);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
