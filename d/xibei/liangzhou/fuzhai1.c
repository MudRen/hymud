//fuzhai1.c 过道
//Hydra

inherit ROOM;

void create()
{
    set("short","过道");
    set("long", @LONG
一条砖石铺成的小道，从门口一直通往大厅。过道两旁种着各种花草，这些
都是这里的主人从别处运来种的，虽然凉州风沙很大，但是由于精心护理，这里
的草都长的不错。北面是大厅。
LONG
    );
    set("outdoors","liangzhou");
    set("exits", ([ 
        "south"         :       __DIR__"door",
        "north"         :       __DIR__"fuzhai_dating",
    ]) );

        setup();
}

