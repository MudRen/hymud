 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        object con,obj;
        set("short", "�ؾ���");
        set("long", @LONG
��������ֻ��ľ������顰��˷�������
LONG
        );
        set("exits", ([ 
  "up"  : __DIR__"changjing3",
  "down" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/gui1" : 2,
                __DIR__"npc/monk6" : 2,
       ]) );
        set("coor/x",-210);
        set("coor/y",230);
        set("coor/z",60);
        setup();
        create_door("down", "ľ��", "up", DOOR_CLOSED);
    con = present("mugui" + sprintf(" %d",random(2)+1), this_object());
        if(con && obj = new(__DIR__"obj/yufe")) obj->move(con);
}   
