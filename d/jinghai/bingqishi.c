inherit ROOM;

void create()
{
        set("short", "山庄兵器房");
        set("long", @LONG
这里就是山庄兵器房
LONG
);

        set("exits", ([
                "north"  : __DIR__"houmen",             
]) );

        setup();
        replace_program(ROOM);
}

