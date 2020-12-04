//written by lnwm on 97/07/08
//shan1.c

#include <ansi.h>

inherit ROOM;

void do_jiefei( object who );

void create()
{
    set("short","青城山脉");
    set("long",@LONG
这里已远离青城后山，位于青藏高原以东，四川盆地西北的重山峻岭之中，这
里山峦起伏，地势十分险要。据传有很多世外的高人就隐居在这片浩瀚的群山之中
由于地势复杂，许多朝廷的钦犯或江洋大盗也喜欢隐藏在这片群山之中。你放眼望
去，四周全是山，几乎不可辨清道路。
LONG);
    set("exits",([
        "east"   	:		__DIR__ "qingcheng_shan3",
		"west"		:		__DIR__ "shan2",
    ]));
    setup();
}

int valid_leave(object me, string arg)
{
    object *inv;
    int i;

    inv = all_inventory(me);

    for ( i = 0; i < sizeof(inv); i++ )
   	{
        if ( userp(inv[i]) && arg == "west" )
             return notify_fail("前面山路崎岖,你只觉的身上背的人越来越重,竟迈不动步了.\n");
	}		

	return 1;
}


