//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "ÅûÏãµî");
set("long", @LONG
ÅûÏãµî ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£      
LONG );


set("magicroom",1);set("exits", ([
  "west"   : __DIR__"taiyanggong",
]));


set("objects", ([
]));



setup();
}
