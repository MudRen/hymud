// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "新手联盟恩怨堂");
set("long", @LONG
这里是新手联盟的恩怨堂
这里是新手联盟的恩怨堂
这里是新手联盟的恩怨堂
这里是新手联盟的恩怨堂
这里是新手联盟的恩怨堂
这里是新手联盟的恩怨堂
、

LONG
);
        set("exits", ([
"west" : "/p/residence/name1433777592.c",
]));
set("objects", ([
	"/p/npc/jobshi":1,
       "/p/npc/weishi":2,
       ]) );
	set("owner", "name");
	set("class", "新手联盟　");
//	set("no_fight",1);

setup();
}
