#include <room.h>
inherit ROOM; 
string look_sign(object me); 
void create()
{
        set("short", "迎梅客栈");
        set("long", @LONG
这是布达拉宫中最大的一家客栈。据说这家店主是一个痴情的年青人。他在这
里开客栈就是希望他当年在中原失散的情人能够知道他在这里，而来与他相会。可
是客栈开业多年，中原客商人来人往，还是没有带来他昔年情人的一点消息。因为
近年土匪横行，客栈生意清淡，店主和王风合伙，也兼代做起了出租马车回风云城
的生意。
LONG
        );
      
        set("valid_startroom", 1);
        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );
        set("exits", ([
                "west"   : __DIR__"octo1",
                "north"   : __DIR__"majiu",
                	]) );
        set("objects", ([
                __DIR__"npc/waiter" : 1, 
            //    "/obj/npc/trashcan":1,
                ]) ); 
        set("coor/x",-1190);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
        
} 
    
