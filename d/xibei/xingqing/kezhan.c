//kezhan.c.客栈
//date:1997.8.28
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"有间客栈"NOR);
        set("long", @LONG
这间客栈也不知开了多长时间了，总之有兴庆城时就有它。由于地处城市中
心，交通便利，生意很红火。店小二里外忙活得团团转。经常有一些江湖豪客在
此落脚，店小二的消息很灵通。墙上写着
        小店各种等级客房，房价一两银子到九两不等，客人请
        自备散碎银两，小店没有零钱可找。
                                      ------有间客栈
LONG
        );
    set("exits", ([ 
                "west"  : __DIR__"road5",
        ]));

        set("objects", ([
                 __DIR__"npc/waiter" : 1,
                ]) );
        setup();
}                       


