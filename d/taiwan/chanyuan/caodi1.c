
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。草地平坦，走起来十分舒服。西边是禅院的兵器
库，东边是一个长廊。不时有几名禅院弟子从你的身旁走过。阵阵梵呗
诵经之声，悠悠扬扬的似从遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "west":__DIR__"bingqiku",
	  "eastup":__DIR__"changlang3",

         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

