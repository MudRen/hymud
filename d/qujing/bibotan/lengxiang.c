#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

������ϵļҾ㶼������ɽ�����е�����ľ�Ƴɣ�������������
�����쳣������֮��������һ˿���������������˲��ɵ�������
������������
LONG);


	set("cold", 1);
//  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shuijg",
]));
//      
        set("water", 1);
//  
  setup();
}

