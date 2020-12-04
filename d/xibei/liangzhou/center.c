//center.c

inherit ROOM;

void create()
{
        set("short","中心集市");
        set("long", @LONG
尘土飞扬,热闹非凡的中心广场.虽说连年的战乱损害了丝绸之路的顺
利敞通,但这里的往来贸易从未停止过.除了来自中原的小贩高声叫卖着手
中的绸缎外, 你还能看到来自西域深鼻高目的外国商人操着半生不熟的中
国话与小贩们讨价还价. 南边是一个当铺,东西通向凉州城的城门,北边一
条直路通向一座寺院.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "lroad3",
                "south"         :       __DIR__ "dangpu",
                "west"          :       __DIR__ "lroad4",
                "east"          :       __DIR__ "lroad2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

