 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
һ���տ��Ļ���Ժ�ӣ�Ժ�Ӻܴ󣬱���һ��С��������һ��СС��ľ�š�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"jialan",
  "south" : __DIR__"neiyuan2",
]));
        set("outdoors", "shaolinfy");
        set("coor/x",-210);
        set("coor/y",320);
        set("coor/z",60);
        setup();
        create_door("northup", "ľ��", "southdown", DOOR_CLOSED); 
}    
