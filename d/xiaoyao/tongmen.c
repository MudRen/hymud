// tongmen.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "铜门");
	set("long", @LONG
这是一个月形的铜门。
LONG );
	set("exits", ([
		"south" : __DIR__"shiji3",
		"west" : __DIR__"fangjian3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
