inherit ROOM;

void create()
{
        set("short", "ɽׯ������");
        set("long", @LONG
�������ɽׯ������
LONG
);

        set("exits", ([
                "north"  : __DIR__"houmen",             
]) );

        setup();
        replace_program(ROOM);
}

