//xiaoyuan2.c.小院
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"厢房"NOR);
    set("long",@LONG
一条卵石铺成的小路，带你进入了一个小院。这里是高台寺为了方便远方来
的客人和四处云游的行者而特地为他们准备的休息的地方。靠墙摆着一溜几张木
床，床上铺的是精致的绣花的床单，床头叠着两床厚厚的棉被。地上整整齐齐的
，清扫得很干净。北面有扇窗户，靠窗的八仙桌上放着一个美轮美奂的花瓶，上
面插着几枝鲜花，散发着芬芳的气息。
LONG);
    set("exits",([
        "east":__DIR__"tianjing2",
    ])); 
    set("sleep_room","inn");
    setup();
}

