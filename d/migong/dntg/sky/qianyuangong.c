//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "Ç¬Ôª¹¬");
set("long", @LONG
Ç¬Ôª¹¬ ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£     
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"shenpinggong",
  "north"   : __DIR__"lingxiao",
]));

set("no_npc",1);
set("objects", ([
]));



setup();
}
