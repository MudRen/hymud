//xiaoyuan1.c.小院
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"厢房"NOR);
    set("long",@LONG
一条卵石铺成的小路，带你进入了一个小院。这里是高台寺僧众们饮食起居
的地方。靠墙摆着一溜几张木床，床上铺的是篾席。床头叠着床薄被，冬天想必
很冷，僧侣们全靠扎实的内功根基御寒。地上整整齐齐的，清扫得很干净。靠南
的一面放着几个破旧的蒲团和木鱼。
LONG);
    set("exits",([
        "west":__DIR__"tianjing2",
    ]));
    setup();
}

