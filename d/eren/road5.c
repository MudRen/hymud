 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
ֻ��ӭ�����һ�����������������ӣ�к����ȣ����ƾ�ֹһ�㣬����������
����龰����ͼ��������ǧ�ȣ�����һ�����٣����̴�é�Ἰ�䡢С��һĨ������
ʫ�顣·���п�ʯ�����������ɷ����д�ż����֡�
LONG
        );
        set("exits", ([ 
        "southup" : __DIR__"road3",
        "east" : __DIR__"valley1",
        ]));
        set("objects", ([
        __DIR__"obj/bei": 1,
        
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1250);
        set("coor/y",2020);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
} 
