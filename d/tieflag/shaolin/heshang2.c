 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���в�");
        set("long", @LONG
���Ǻ�����ӵĳ��������Ӻܳ������ŷ������ų�ľ���������Ǳ�
������ϯ��һ�����������ڽ�ּ��Ҫ�������ж��֣��������ڵ����޲�
ʱ���������С����϶���ϰ���գ����Լ����϶���Ҳ����˰��ޡ�
LONG
        );
        set("exits", ([ 
 "west" : __DIR__"neiyuan2",  
 "north" : __DIR__"heshang3",
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
                __DIR__"obj/zhuxi" : 1,
                __DIR__"npc/laomonk4" : 1,
       ]) );
        set("coor/x",-200);
        set("coor/y",310);
        set("coor/z",60);
        setup();
create_door("north", "ľ��", "south", DOOR_CLOSED);
}
