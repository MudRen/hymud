#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "青石小路");
  set ("long", @LONG
 这是一条向东的青石大道，两边是一排排的乡间小屋。
LONG);
  set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"zhp",
"north" : __DIR__"sleep",
"east" : __DIR__"lw",	
"west" : __DIR__"welcome",
]));
  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"jing" : 1,
 
]));
  set("outdoors","welcome");
//  set("sleep_room", 1);

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}