#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "/d/migong/randomh.c"
void create()
{
		set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong7"+(random(4)+5),
		"south" : __DIR__"dong11",
                "west" : __DIR__"dong8"+(random(4)+5),
                "north" : __DIR__"dong98",
	]));

         
	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
