// wofang.c ɽׯ�Է�

inherit ROOM;

void create()
{
        set("short", "�Է�");
        set("long", @LONG
������һ���Է�
LONG
);
        set("sleep_room", "1");
        set("exits", ([
                "northeast" : __DIR__"guodao1",
]) );
 
        setup();
        replace_program(ROOM);
}

