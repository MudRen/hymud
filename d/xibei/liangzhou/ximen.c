//ximen.c

inherit ROOM;

void create()
{
        set("short", "凉州西门");
        set("long", @LONG
河西咽喉凉州的西门,这里已是西夏的辖区,城楼上飘扬着五色的锦旗
两扇镶满巨大铜钉的城门紧闭着,只有两侧的角门让行人和车辆通过.许多
全副武装的兵丁在城下来回巡视, 每一个可疑的过往行人都会被他们盘查
一番.城门两侧城墙上贴着几张捉拿间谍的牒文.
LONG
        );
set("outdoors","liangzhou");
        set("exits", ([ 
               "west"           :       "/d/xibei/silk1",

                "east"          :       __DIR__ "lroad5",
                ]) );

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ])); 
        
//      replace_program(ROOM);
        setup();
}

