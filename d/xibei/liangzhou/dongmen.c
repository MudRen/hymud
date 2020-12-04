//dongmen.c

inherit ROOM;

void create()
{
        set("short", "凉州东门");
        set("long", @LONG
河西咽喉凉州的东门,这里已是西夏的辖区,城楼上飘扬着五色的锦旗
两扇镶满巨大铜钉的城门紧闭着,只有两侧的角门让行人和车辆通过.许多
全副武装的兵丁在城下来回巡视, 每一个可疑的过往行人都会被他们盘查
一番.城门两侧城墙上贴着几张捉拿间谍的牒文.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
             "east"     :       "/d/xibei/lianglu8",
                "up"            :       __DIR__ "guan",
                "west"          :       __DIR__ "lroad1",
                ])
        );
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));        
//      replace_program(ROOM);
        setup();
}

