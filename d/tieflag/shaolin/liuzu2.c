 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������޵����ԣ����������䣬����������Ħ������ۿɣ�����
ɮ�ӣ�������ţ�������̣���������������й��������������Ϊ
�����泯������������ǽ�ڻ�����������ɮ����ȷ�Ƿ�ұ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"liuzu",
]));
        set("objects", ([
                __DIR__"npc/xin_qian" : 1,
       ]) );
        set("coor/x",-230);
        set("coor/y",210);
        set("coor/z",40);
        setup();
        create_door("east", "ľ��", "west", DOOR_CLOSED); 
}
