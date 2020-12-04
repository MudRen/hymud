//shanmen.c

inherit ROOM;

void create()
{
        set("short","大云寺山门");
        set("long", @LONG
凉州闻名的寺院,相传为西域高僧鸠摩罗什舍利所居之地.寺院建筑古
朴凝重,山门门梁修得甚是气派,飞檐斗拱,异彩流光 .正中悬着一块大匾
, 用重墨书写"大云寺"几个大字.两侧山墙各写着一个巨大的"佛"字.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "lroad3",
                "north"         :       __DIR__ "tingyuan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

