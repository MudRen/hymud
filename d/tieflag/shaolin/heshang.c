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
 "east" : __DIR__"neiyuan2",  
 "north" : __DIR__"heshang4",
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
                __DIR__"obj/zhuxi" : 1,
                __DIR__"npc/laomonk3" : 1,
       ]) );
        set("coor/x",-220);
        set("coor/y",310);
        set("coor/z",60);
        setup();
 create_door("north", "ľ��", "south", DOOR_CLOSED);
}       
