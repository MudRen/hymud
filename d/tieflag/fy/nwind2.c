inherit ROOM;
void midnight_event();
void sunrise_event(); 
void create()
{
        set("short", "北风街");
        set("long", @LONG
这里是风云广场的北边，再往北眺望可以看到远处高耸的城墙。热闹的街道上
充溢着清新的花香和甜丝丝脂粉的香气。花香是从大街东侧的飘香花店荡漾出来的，
而浓厚的脂粉气息则是西首倾城胭脂店的招牌。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind1",
                "north" : __DIR__"nwind3",
                "east" : __DIR__"pxhdian",
                "west" : __DIR__"qcyzdian",
        ]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",0);
        setup();
//        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
