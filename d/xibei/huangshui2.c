#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","湟水");
    set("long",@LONG
湟水如一条晶莹的玉带，从西向东流过，河水在阳光照耀下波光粼粼，如同
满天星辰都坠入了河里一般。北面山下有一座大城，过往客商都称其为“青唐城
”。此城原来是蕃部一小国的都城，后来被朝廷占领。因其扼守中原同西域之路
，历来是来往客商聚集之地，商业发达。南面是积石山，西面是日月山，崇山峻
岭环绕三方，只有东面地势渐低。
LONG);
    set("exits",([
        "east"   : __DIR__"huangshui1",
        "westup"    : __DIR__"riyue_shan",
    ]));
    set("outdoors","xibei");
    setup();
}

