// fangjian3.c
// by shilling 97.2
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的木头
制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG );
	set("exits", ([
		"east" : __DIR__"tongmen",
	]));
	set("objects",([
		"/clone/book/bojuan" : 1,
	]));
//	set("no_clean_up", 0);
	set("book_count",1);
	setup();
}

