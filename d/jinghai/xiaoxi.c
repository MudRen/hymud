// xiaoxi.c 庄外小溪

inherit ROOM;

void create()
{
        set("short", "涓涓溪流");
        set("long", @LONG
这里是一条溪流.
LONG
);

        set("exits", ([ /* sizeof() == 2 */
        "southwest" : __DIR__"damen",
        "northeast" : __DIR__"muqiao",
]));

        set( "GATE_ROOM",1 );
        set( "gate_dir",(["southwest" : __DIR__"damen"]) );

        set( "close_look",@LONG
这里是桃花庄门外。东北面是一条桃林小路静悄悄的向远处延伸，
向西南不远处就是著名的桃花庄北门，天色已晚，庄门已经关上了。
LONG
);

        set( "gate_name","桃花庄正门" );
        set("outdoors","jinghai");
        setup();
        replace_program(ROOM);
}

