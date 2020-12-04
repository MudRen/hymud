// xiaowu.c
inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
你进了这间小屋以后，发现这里竟然和你想象的差别很大，这里
虽然不能说是金碧辉煌，但到处都是玉制的物器，玉桌，玉椅，玉屏
风，玉茶壶，玉杯......数不胜数。墙上挂着一根绿玉萧和一具白玉
瑶琴。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" : __DIR__"xiaoyuan",
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/huangzhong-gong" : 1,
            __DIR__"obj/wall" : 0,
                "/quest/menpai/newmp/shi8" : 1,
                "/d/biwu/champion_mz" : 1,
                "/d/meizhuang/npc/mdizi" : 2,
                "/d/meizhuang/npc/jiading2" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "meizhuang");

        setup();
        replace_program(ROOM);
}

