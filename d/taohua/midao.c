// /u/beyond/mr/midao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIM"秘道"NOR);
         set("long",@long
这里土地潮湿，墙上有一束火把。当年桃花弟子为了有事直达中原而挖凿的。
long);
         set("exits",([
    "north" : "/d/taohua/houyuan",
    "south" : "/d/city/kedian",
]));
  set("no_npc", 1);
  set("no_clean_up", 0);

         setup();
	 replace_program(ROOM);
}
