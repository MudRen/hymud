 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ǧ���");
        set("long", @LONG
������¬�󣬵����൱���£����������С�����ʥ�ˡ������ң���
ǰ��̨����ʯ�������������е������������¬ͭ�����ڶ����
�����ϣ���а������ް����ӷ�һ�����ܱڻ���������������עĿ
���ǵ��ϵ���ʮ�˸����ݵĽſӡ�
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"neimen",
  "southdown" : __DIR__"lishi",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"dizang",
]));
        set("objects", ([
                __DIR__"obj/footstep" : 1,
       ]) );
        set("coor/x",-210);
        set("coor/y",280);
        set("coor/z",70);
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED);
}    
