
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
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
	]));

	set("no_clean_up", 0);
	setup();
	initlvl();
	replace_program(ROOM);
}
