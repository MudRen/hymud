#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ߵ�");
        set("long", @LONG
���澹�������ص��������ǵ�̾��µ�ʯ�ڣ�����Ƕ�ŷ�����ͭ�ơ�
�ص�����������ͷ����һ���ţ�������Ҳ�����һЩ���ﻨ�ݣ���������
ֻ�������ص����Ͳ�֪���˶���������������������˿ϻ���ô�������
�����ڵ��½������ߵ������治֪�Ǹ�ʲô���Ĺ��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace3",
                "south" : __DIR__"palace1",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        create_door("south","ʯ��","north",DOOR_CLOSED);
}      
