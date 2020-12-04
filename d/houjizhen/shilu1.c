// shilu1.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "碎石路");
	set("long", @LONG
这是一段碎石路，路是用许多石块铺成的，铺的整整齐齐，
大路由东向西，一直通向侯集镇的尽头，路的北边是一家客栈，
客栈前面树立着一旗杆，上面挂着一张破破烂烂的招牌，几缕
阳光从招牌破洞之间的缝隙照下来，在地上撒下点点光斑，旗
杆下面站着一位女孩，特别的引人注目。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu2",
	    "north" : __DIR__"kedian",
	    "south" : __DIR__"majiu",
	    "east" : __DIR__"paifang",
	]));

	set("objects",([
		__DIR__"npc/gunv" : 1,
	]));

	setup();
	replace_program(ROOM);
}
