// hean.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "河岸");
        set("long", @LONG
这里是光秃秃的河岸，下面河流湪急，四下都是乱坟。
LONG);

        set("outdoors", "houjizhen");

        set("exits", ([
		"north" : __DIR__"muqiao",
        ]));

	setup();
	replace_program(ROOM);
}
