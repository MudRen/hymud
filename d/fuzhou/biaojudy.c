// Room: /city/biaojudy.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "福威镖局大院");
	set("long", @LONG
大院里显得有些凌乱，趟子手和镖师们进进出出，似乎
都在满地里忙碌着什么。一棵很大的榕树栽在院子中央，给
火辣辣的福州带来一点凉爽。
LONG );
	set("exits", ([
		"out"   : "/d/fuzhou/biaoju",
		"north" : "/d/fuzhou/biaojuzt",
	]));
	set("objects", ([
		//__DIR__"npc/shi" : 1,
		"/d/jinyong/book8/fuzhou/npc/shi" : 1,
	]));
	set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

