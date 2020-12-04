inherit ROOM;

void create()
{
        set("short", "小胡同");
        set("long", @LONG
这里是一条小胡同，就在白天这里也是昏暗不堪。这里似
乎到了胡同的尽头，有一扇门紧关着。
LONG);
	set("outdoors", "zhongzhou");
        set("exits", ([
                "north"     : __DIR__"liwu",
                "southwest" : __DIR__"hutong1",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 1,
        ]));

        set("coor/x", -220);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

