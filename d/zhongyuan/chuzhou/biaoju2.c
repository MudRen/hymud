// 楚州扬威镖局南 /d/city/chuzhou/biaoju2.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"扬威镖局"NOR);
    set("long", @LONG
扬威镖局的南院原先是堆放货物和车辆的，但是因为现在没有什么生意可做，
所以就改堆放杂物了。也兼做练功之用。一位壮汉和一位年轻人正在往墙上钉一
块你看起来很眼熟的牌子。
LONG
    );
    set("no_kill",  "yangzhou");
    set("outdoors", "chuzhou" );
    set("detail", ([
        "牌子"  : "与人练功夫一次，收银五两。\n",
        "paizi" : "与人练功夫一次，收银五两。\n",
        "sign"  : "与人练功夫一次，收银五两。\n",
    ]));        
    set("exits", ([
        "north"  : __DIR__"biaoju",
        ]));
    set("objects", ([
        __DIR__"npc/lin_tianhao"     :   1,
        __DIR__"npc/lin_tianxiong"   :   1,
    ]));        
    setup();
}
