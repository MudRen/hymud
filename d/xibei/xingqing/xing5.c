// room: xing5.c
//by lnwm 97-09-12


inherit ROOM;

void create()
{
        set("short", "黄河沿岸");
        set("long", @LONG
走出山区, 你眼前是一片夹在群山和黄河之间的平原. 这里已是西夏领地, 
再往前就是西夏的首府兴庆府. 行至这里, 人烟渐渐增多了起来, 你能感到, 这
里的风土文化已与中原有显著得不同. 
LONG
        );
    set("exits", ([ 
                "southwest"     :       __DIR__ "xing4",
                "northeast"     :       __DIR__ "xing6",
        ]));
        set("outdoors","xingqing");
        setup();
}                       


