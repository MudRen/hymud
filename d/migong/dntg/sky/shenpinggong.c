//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "À¤Æ½¹¬");
set("long", @LONG
À¤Æ½¹¬ ³¤ÁºµñÁú£¬·ÉéÜ»­·ï¡£ÀïÃæµî¸ó¸ß´ó
ĞÛÎ°£¬²ã²ãµşµş£¬ÁğÁ§Íß°×ÓñŞò¸»ÀöÌÃ»Ê¡£       
    
LONG );


set("magicroom",1);set("exits", ([
  "south"   : __DIR__"taiyanggong",
  "north"   : __DIR__"qianyuangong",
]));


set("objects", ([
]));



setup();
}
