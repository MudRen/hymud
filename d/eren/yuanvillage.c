 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����ɽׯ");
        set("long", @LONG
Ԭ�ұ���������׻�������Ԭ�ҵİ���ɽׯ����������Χ�˰��������˭��֪��
���أ����ο����첻ͬѰ������Ԭ�Ҵ���үԬ�����������ǧ��������׵Ĵ�ϲ֮
�ա���ǰ��ˮ����������ǰ����ϲ����Ⱥ��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"yuanvillage2",
                "south": __DIR__"road1e",
        ]));
        set("objects", ([
                
        ]) );
set("coor/x",-1090);
        set("coor/y",180);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
