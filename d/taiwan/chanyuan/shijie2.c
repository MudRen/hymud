
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石阶");
  set ("long", @LONG
这里是一排石阶。西边是净念禅院的文殊大殿，往东去就是禅院的
无量殿了。这里可以听到阵阵梵呗诵经之声，悠悠扬扬的似从遥不可知
的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"wenshudian",
	  "eastup":__DIR__"wuliangdian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

