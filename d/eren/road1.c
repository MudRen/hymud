 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ·������᫣���ʯ���м���Ұ����ǿ�����ͷ����Ⱥɽ����Զ���������ڽ�
��������¼ŵ�ɽ���ȴ���˵ĵ��ϣ���¶���˼����İ�Ϣ��
LONG
        );
        set("exits", ([ 
        "southdown" : __DIR__"road0",
        "southup" : __DIR__"road2",
        "westup" : __DIR__"road1a",
        ]));
        set("objects", ([
                __DIR__"obj/grass": 1,
        ]) );
        set("outdoors", "eren");
set("coor/x",-1020);
        set("coor/y",165);
        set("coor/z",15);
        setup();
        replace_program(ROOM);
}  
