//fuzhai_zoulang.c 走廊
//Hydra

inherit ROOM;

void create()
{
    set("short","走廊");
    set("long", @LONG
这是一条长长的走廊，通向内宅。雕花的栏杆外面是一个小花园，走廊顶上
面刻着一些画。
LONG
    );
    set("outdoors","liangzhou");
    set("exits", ([ 
        "north"         :       __DIR__"fuzhai_zoulang2",
        "west"          :       __DIR__"fuzhai_dating",
    ]) );

        setup();
}

