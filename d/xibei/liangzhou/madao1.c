//madao1.c

inherit ROOM;

void create()
{
        set("short","马道");
        set("long", @LONG
城楼上下交通所用的马道,左右很宽, 用厚厚的砖石砌成,斜斜地通到
城下.因为战乱还没有结束, 一队一队的西夏士兵城上城下来回地巡逻,他
们个个身背明亮的腰刀，足登厚厚的鹿皮靴，身着利落的皮衣，它们的装
束已经与中原的士兵显然不同.
LONG

        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "guan",            
                "north"         :       __DIR__ "cheng1",
                ])
        );
//      replace_program(ROOM);
        setup();
}

