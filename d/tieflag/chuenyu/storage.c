#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "������");
        set("long", @LONG
һ��СС�Ĵ����ҡ��ı��ϲ����˻ҳ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west_blackge",
]));
        set("objects", ([
                "/clone/weapon/gangjian" : 5,
        ]) ); 
        create_door("north", "ľ��", "south", DOOR_CLOSED);
        set("coor/x",110);
        set("coor/y",180);
        set("coor/z",40);
        setup();
}        
