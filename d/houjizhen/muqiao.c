// muqiao.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "木桥");
	set("long", @LONG
这是一座年久失修的破木桥，由几根树干捆扎而成。下面的河水早以结
成坚冰。这里是天山积雪融化汇集成的一条河流，河水长流不息。河岸北面
是一座财神庙，土堆成的城墙，很多处都已坍塌。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([
		"south" : __DIR__"hean2",
		"north" : __DIR__"hean1",
		"east" : __DIR__"shilu6",
                "west" : "/d/ruzhou/xiaozheng",
	]));

        set("objects", ([
               "/clone/npc/npc1" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
