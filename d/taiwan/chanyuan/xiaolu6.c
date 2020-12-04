
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是净念禅院的小路。西面是禅院的诵经房。往东走可以到禅院
的武场，那里传来了阵阵吆喝声音。阵阵梵呗诵经之声，悠悠扬扬的似
从遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	 
	  "northeast":__DIR__"caodi4",
	  "west":__DIR__"songjingfang",
      ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

