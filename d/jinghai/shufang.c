inherit ROOM;

void create()
{
        set("short", "ɽׯ�鷿");
        set("long", @LONG
�������ɽׯ�鷿
LONG
);

        set("exits", ([
                "north"  : __DIR__"qianyuan",
]) );

        setup();
        replace_program(ROOM);
}

