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
        "southdown" : __DIR__"yuzhu",
        "northup" : __DIR__"road1",
        ]));
        set("objects", ([
                __DIR__"obj/grass": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1020);
        set("coor/y",160);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}       
