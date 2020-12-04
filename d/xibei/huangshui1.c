#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","湟水");
    set("long",@LONG
湟水如一条晶莹的玉带，从西向东流过，河水在阳光照耀下波光粼粼，如同
满天星辰都坠入了河里一般。北面是山势陡峭的达坂山，山上人烟稀少，地势荒
凉，只有稀稀疏疏的几棵小树，偶尔有些放牧的山民赶着羊群走过。河边谷地中
沿河两岸种满了谷子，高粱；南边是积石山，山脚下有些村庄，东边是一片荒野
。
LONG);
    set("exits",([
        "east"   : __DIR__"huangye1",
        "west"    : __DIR__"huangshui2",
    ]));
    set("outdoors","xibei");
    setup();
}

