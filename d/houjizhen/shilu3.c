// shilu3.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "碎石路");
	set("long", @LONG
这是一段碎石路，路是用许多石块铺成的，铺的整整齐齐，
大路由东向西，一直通向侯集镇的尽头，南边是一家兵器铺，
北边是一家民家小院，路上几乎没有什么行人。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu4",
	    "south" : __DIR__"bingqipu",
	    "north" : __DIR__"minju",
	    "east" : __DIR__"shilu2",
	]));

	setup();
	replace_program(ROOM);
}
