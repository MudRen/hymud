// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>
#define BOARD_TOC "/doc/board/toc2"
#define BOARD_DIR "/doc/board/"
inherit ROOM;
string look_shu();

void create()
{
	set("short", "名人堂");
	set("long", @LONG
这里就是侠客行一百的名人堂。在这里供奉的有大侠，也有魔头，
也有不是大侠不是魔头的玩家。无论是哪一位，都曾冠绝一时，都有
一个长长而惊心动魄的故事，每一个故事都曾很深远地影响了一代甚
至两三代玩家。
    虽然他们都曾经轰轰烈烈掀起满江湖的风雨，如今，他们再也不
会在江湖出现了。他们都已经退出江湖，但他们的侠影魔踪很长时间
以后仍是一个传说。

LONG );
set("chatroom",1);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"wumiao2",
	]));
	set("objects", ([
	]));
	setup();
	//replace_program(ROOM); 
}

void init()
{
        //add_action("do_read", "yuedu");
}

string look_shu()
{
        this_player()->start_more(read_file(BOARD_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        int line;
        if(!arg)
        return notify_fail("请输入要看的文件和起始行号。(比如说yuedu book1.txt 0)\n");
        
        if(!sscanf(arg, "%s %d", arg,line))
        return notify_fail("请输入要看的文件和起始行号。(比如说yuedu book1.txt 0)\n");
        
        if (arg == "" || file_size(BOARD_DIR + arg) <= 0)
                return notify_fail("好象没有这条公告耶。\n");

        //log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        //me->start_more(read_file(BOARD_DIR + arg));
        me->more("", explode(read_file(BOARD_DIR + arg), "\n"), line);
        return 1;
}

