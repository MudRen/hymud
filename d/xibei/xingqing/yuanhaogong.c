//yuanhaogong.c.元昊宫
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"元昊宫"NOR);
    set("long",@LONG
面前是一座避暑宫苑，名为“元昊宫”。此地原是一沼泽地，元昊令人模仿
唐长安地的兴庆宫和曲江池，建起了这以水景为主的元昊宫，“逶迤数里，亭榭
台池，并极其胜。”宫门有铁鹞军把守，戒备森严.
LONG);
    set("exits",([
         "south"  : __DIR__"road22",
    ]));
    set("outdoors","xingqing");
    setup();
}

