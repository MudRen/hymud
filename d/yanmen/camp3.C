// #pragma save_binary
// ROOM:__DIR__"camp3"

inherit ROOM;
void create()
{
        set("coor",({-250,4260,0}));
	set("short","小兵营帐");
	set("long",
"这是个由粗略的布料所搭成的小营帐，里面只有三二个小兵，其他的小兵，大概在另一个小\n"
"兵营帐里赌博聊天吧，而东边则是小队长的营帐。\n"
); // eof(long)

	set("exits",([ /* sizeof()==1*/
		"south" : __DIR__"camp1",
	]) ); //eof(exits)

	set("objects",([
		__DIR__"npc/guard1" : 1,
	]) );

	setup();

	replace_program(ROOM);
} //EOF
