// Room: /city/dongxiang.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�̼ҵ���");
	set("long", @LONG
����һ���谵�ĵ��Σ������������������Ϸ���Ƥ�ޡ�ľ�����̾ߡ�
LONG );
	set("exits", ([
		"south" : __DIR__"shang_lianwun",
	]));
	set("objects", ([
		__DIR__"npc/shang_zhao" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

