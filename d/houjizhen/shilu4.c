// shilu4.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "碎石路");
	set("long", @LONG
这是一段碎石路，路是用许多石块铺成的，铺的整整齐齐，
大路由东向西，一直通向侯集镇的尽头，北边是一家茶馆，茶馆
前面的幌子在风中无力的摇摆。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu5",
	    "north" : __DIR__"jiuguan",
	    "east" : __DIR__"shilu3",
	]));

	setup();
	replace_program(ROOM);
}
