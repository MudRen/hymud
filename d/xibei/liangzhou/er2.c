//er2.c

inherit ROOM;

void create()
{
        set("short","东耳房");
        set("long", @LONG
一排青瓦红窗的禅房,供僧人们起居和打座参禅的地方.
LONG
        );
        set("exits", ([ 
                "west"          :       __DIR__ "tingyuan",
                ])
        );
//      replace_program(ROOM);
        setup();
}

