//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "云路");
set("long", @LONG
踏着这条宽敞的天宫云路，脚下飘过朵朵白云，俯视人间农舍
中飘起的袅袅炊烟，另人倍感心旷神怡。
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"yunluw2",
  "west"   : __DIR__"yunluw4",
  "north"   : __DIR__"hgj4",
  "south"   : __DIR__"hgj3",
]));


set("objects", ([
]));



set("outdoors", "dntg");

setup();
}
