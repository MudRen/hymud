 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��¶̨");
        set("long", @LONG
��˵�����뾭���콵��¶��������Ϊ��¶̨��̨������Űأ�̨��
���ù������Ѹ�¶̨���Ű�ס����¶̨�гɰ��Σ������һ����ˮ����
���겻�ɿݡ�
LONG
        );
        set("exits", ([ 
        "eastdown" : __DIR__"tayuan",   
        ]));
        set("objects", ([
                __DIR__"npc/master_21" : 1,
       ]) );
        set("resource/water", 1);
        set("liquid/container", "��¶̨");
        set("outdoors", "shaolinfy");
        set("coor/x",-230);
        set("coor/y",260);
        set("coor/z",60);
        setup();
        create_door("eastdown", "ľ��", "westup", DOOR_CLOSED);
}        
