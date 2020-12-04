// baling/edao1
// Room in 巴陵
inherit ROOM;

void create()
{
	set("short", "铜梁县");
	set("long", @LONG
你顺着大驿道向前走，渐渐的走进了山里，一边是高入云天的高山
峻岭，一边是陡峭的山崖，你往峡谷下望去，感觉到一阵眩晕，你不得
小心的行走，行人的速度也都缓慢了下来.	
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"shandao7",
                "northeast" : __DIR__"anle",
	]));

 	set("outdoors", "baling");
	setup();
	replace_program(ROOM);
}


