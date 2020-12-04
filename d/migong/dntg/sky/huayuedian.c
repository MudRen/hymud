//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "»ªÀÖµî");
set("long", @LONG
»ªÀÖµî ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£ 
LONG );


set("magicroom",1);set("exits", ([
  "east"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
