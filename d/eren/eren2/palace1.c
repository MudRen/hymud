#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ߵ�");
        set("long", @LONG
��Ͳ�ӡ��ڶ����ϿĿ����������½�������Ŀ�����ø�����������
����ã��ǡ�Ͳ�ӡ�����ͣ�ˣ���ǰһ�����ֳ���һ���ţ�һƬ�����ɵ�
���ߣ����������˽����������������ߵ����ߵ����������Կ�����һ�˵�
�š�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        create_door("north","ʯ��","south",DOOR_CLOSED);
}   
