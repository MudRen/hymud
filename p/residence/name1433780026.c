// a skeleton for user rooms
inherit ROOM;
void create()
{
set("short", "任务堂");
set("long", @LONG
这里是新手联盟的任务堂
这里是新手联盟的任务堂
这里是新手联盟的任务堂
这里是新手联盟的任务堂
这里是新手联盟的任务堂
这里是新手联盟的任务堂

LONG
);
        set("exits", ([
"east" : "/p/residence/name1433777592.c",
]));
set("objects", ([
	"/p/npc/shi":1,
       "/p/npc/weishi":2,
       ]) );
	set("owner", "name");
	set("class", "新手联盟　");
//	set("no_fight",1);

setup();
}
