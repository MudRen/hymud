//lroad2.c

inherit ROOM;

void create()
{
        set("short","沙土路");
        set("long", @LONG
凉州城的主干道,虽不是太平年代,但依然十分热闹，行商走贩来来往
往， 整个道路尘土飞扬， 官府的衙役吆喝着试图从人丛中开出一条路来
路南你可以看到一座七层佛塔，塔上风铃随风发出悦耳的声音；路北是一
家药铺；向西就是城中心。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
//                "north"         :       __DIR__ "yaopu",
                "south"         :       __DIR__ "fota1",
                "west"          :       __DIR__ "center",
                "east"          :       __DIR__ "lroad1",
                "north"         :       __DIR__"door",
                ])
        );
//      replace_program(ROOM);
        setup();
}

