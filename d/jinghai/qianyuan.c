inherit ROOM;

void create()
{
        set("short", "ɽׯǰԺ");
        set("long", @LONG
�������ɽׯǰԺ
LONG
);

        set("exits", ([
                "west"           : __DIR__"taohuayuan",
                "east"       : __DIR__"damen",
                "south"       : __DIR__"shufang",
]) );
        set("outdoors","jinghai");

        setup();
        replace_program(ROOM);
}

