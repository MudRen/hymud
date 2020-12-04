// shanlu5.c
// by dicky

inherit ROOM;

void create()
{
        set("short","山路");
        set("long", @LONG
你走在一条偏僻的山路上，四周灌木丛丛，遍地奇花异草，人迹
罕至，路径几不可寻，只有采药的人才敢进入深山。你到处乱窜寻找
出路，猛的一痛，荆棘把你给划伤了!
LONG                           
        );

	set("outdoors", "houjizhen");

        set("exits", ([
		"westup" : __DIR__"qiaobi",
		"southdown" : __DIR__"guanmu",
		"eastdown" : __DIR__"shanlu4",
		"north" : __DIR__"chating",
        ]));

        setup();
        replace_program(ROOM);

}

