//fuzhai_dating.c 大厅
//Hydra

inherit ROOM;

void create()
{
    set("short","大厅");
    set("long", @LONG
这里是张员外家的客厅，四周的墙上挂满了各式字画，东西靠墙处摆着几张
椅子，北面墙边放着一张桌子。由于张员外乐善好施，在凉州城里很有威望，所
以不是有凉州百姓到这里请他帮忙，他一般也都乐于帮助，就在这里接待来访的
百姓。
LONG
    );
    
    set("exits", ([ 
        "south"         :       __DIR__"fuzhai1",
        "east"         :       __DIR__"fuzhai_zoulang1",
    ]) );
    set("objects",([
        __DIR__"npc/zhang"      :   1,
    ]) );

        setup();
}

