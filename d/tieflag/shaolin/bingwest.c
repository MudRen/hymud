 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ɮ��Ժ");
        set("long", @LONG
���Ƕ���ɮ��������������Ķ��Ƕ��־�Ӣ�����г���Զʤ����Ժ��
�ϵ���ϯ����˿�񱻣����������ֻ���ÿ��ǰ���к�ľ��һ�ţ�����
���м�λ����ɮ��רְ��ɨ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"luohan",
  "west" : __DIR__"wuku",
]));
        set("coor/x",-220);
        set("coor/y",340);
        set("coor/z",70);
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED);
}   
