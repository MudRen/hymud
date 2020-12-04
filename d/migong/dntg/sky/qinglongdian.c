//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ÇàÁúµî");
set("long", @LONG
ÇàÁúµî ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£ 
LONG );


set("magicroom",1);set("exits", ([
  "west"   : __DIR__"xuanyuantang",
  "east"   : __DIR__"xinyuegong",
]));


set("objects", ([
]));



setup();
}
