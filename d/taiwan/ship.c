
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","扁舟");
  set ("long", @LONG
这里是艘扁舟。梢公正在吃力地摆着舵。
LONG);

set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

