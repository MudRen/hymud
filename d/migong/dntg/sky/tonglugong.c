//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "疃卢宫");
set("long", @LONG
天宫的一座偏殿，天神进宫面见玉帝之前常在此歇息，
只见这里四壁描龙绣凤，气势非凡。
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"bishagong",
  "north"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
