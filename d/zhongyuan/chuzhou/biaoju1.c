// 楚州扬威镖局北 /d/city/chuzhou/biaoju1.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"扬威镖局"NOR);
    set("long", @LONG
这是楚州扬威镖局的北院。周围是一排青砖平房，是林老镖头一家的住房。
院子里虽然是土地，但是扫得很干净，院中央的大树下，放着小桌和板凳。在门
口放着块牌子。一位壮汉正看着你。
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
        "south"  : __DIR__"biaoju",
        ]));
    set("objects", ([
        __DIR__"npc/lin_tianbao" :   1,
    ]));        
    setup();
}
