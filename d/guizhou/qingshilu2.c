inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一条由青色条石铺成的大道，道面由四辆马车并行那样宽，
所以这条大道上的车马行人来往不断。
LONG );

	set("exits", ([
               "south"      : __DIR__"qingshilu1",
               "northeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



