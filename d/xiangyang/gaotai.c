// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��̨");
	set("long", @LONG
������������ĸ�̨��̨�¶�����ľ�ĺ�����֮�
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"down"  : __DIR__"caodi1",
	]));
	set("objects", ([
		
		__DIR__"npc/guoxiang"   : 1,

	]));
	setup();
	//replace_program(ROOM);
}

