 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
���Ƕ�����⣬�����Դ�������������Ϊ�������й������Կ�����
ӵɮ����������������������������������ʦ�䷢���֣�Э�����죬��
������������Ŀ����ɫ��������һӦ��ȫ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bingwest",
]));
        set("objects", ([
                "/clone/weapon/gangjian" : 1,
                "/clone/weapon/gangzhang" : 2,
       ]) );
        set("coor/x",-230);
        set("coor/y",340);
        set("coor/z",70);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED);
}    
