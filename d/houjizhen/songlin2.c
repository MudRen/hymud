// songlin2.c
// by dicky

inherit ROOM;

void create()
{
        set("short","山腰松林");
        set("long", @LONG
你走在山腰松林中，这片松林环山生成，蔚蔚葱葱，象是贵妇人
的绿裙褊，把这里装扮得更加婀娜多姿! 两边是茂密的松树林，偶尔
有被惊吓的山鸡从你旁边的草丛里飞出，你刚要去抓，它却又飞入了
草丛。
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southwest" :__DIR__"songlin1",
                "eastdown" :__DIR__"shanlu1",
                "northwest" :__DIR__"guanmu",
        ]));
        
        setup();
        replace_program(ROOM);

}

