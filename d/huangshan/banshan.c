 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "半山寺");
        set("long", @LONG
黄山险峻，过去少有人烟，最早来此者多为出家苦修的僧人，所以
黄山之上寺庙甚多。半山寺就因为出了一位擅长山水的大画家“雪庄和
尚”而名声居众寺之首。至今寺内尚有其真迹留传。由半山寺西行下山
便是醉石，继续攀爬可去天都峰。
LONG
        );
    set("exits", ([ 
                "southdown" : __DIR__"mroad3",
        ]));
        set("objects", ([
                __DIR__"npc/xiaofan" : 1,
"quest/skills2/wunon/non/nontian" : 2,
        ]));     
    set("outdoors", "huangshan");
        set("coor/x",-550);
    set("coor/y",-490);
    set("coor/z",30);
        setup();
        replace_program(ROOM);
}   
