//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "Ì«Ñô¹¬");
set("long", @LONG
Ì«Ñô¹¬ ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£       
LONG );


set("magicroom",1);set("exits", ([
  "north"   : __DIR__"shenpinggong",
  "south"   : __DIR__"tonglugong",
  "west"   : __DIR__"huayuedian",
  "east"   : __DIR__"pixiangdian",
]));


set("objects", ([
]));



setup();
}
