// road.c

inherit ROOM;
#include <ansi.h>;

void create ()
{
  set ("short", "阴深小路");
  set ("long",
"这条深山阴凉小道，白天去行走，小道曲径通幽，林萌小路显得阴暗非常，\n阴深的有种说不出的感觉，别说是跳出个强人了，便是跳出只鬼来也是不希罕的\n"NOR

);

  set("outdoors", "gaochang");
  set("no_npc", 1);
   set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : "/d/xingxiu/silk2",
]));

  setup();
  replace_program(ROOM);
}
