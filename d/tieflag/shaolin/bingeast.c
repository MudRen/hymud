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
  "west" : __DIR__"luohan",
  "east" : __DIR__"yaoku",
]));
        set("coor/x",-200);
        set("coor/y",340);
        set("coor/z",70);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED);
}  
