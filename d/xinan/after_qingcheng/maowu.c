
//Writen by lnwm on 97/07/11

//maowu.c

#include <ansi.h>

inherit ROOM;

void do_refuse( object who);

void create()
{
        set("short", "小茅屋");
        set("long", @LONG
茅屋的里边和外边一样得整洁，陈设简单。一张翠绿的竹榻摆放在屋子的
一角。四壁空空，只在正北的墙上挂着一幅水墨山水，画纸已微微发黄，显然
年头不短。屋脚的水缸中盛满了水，水清澈见底，应是从外面小溪中灌来的。
LONG
        );
       set("exits", ([
            "out" 		:		__DIR__ "shanpo",
		]));
        set("objects", ([		
		 __DIR__ "npc/shenren": 1,
		]) );
        setup();
}

void init()
{
    object who;
    who = this_player();
    if( !userp( who ) ) return;
    do_refuse( who );
}

void do_refuse( object who )
{
	if( who->query_temp("lnwm/不可进",1))
	{
		tell_object(who,CYN"\n白衣老人冷哼了一声，这是你自己找死！\n"NOR);
		tell_object(who,RED"\n你只觉得眼前白影一闪，你只觉得嗓子眼一阵发甜，就什么也不知道了。\n"NOR);
		who->die();
		return;
	}	
	else
	{
		tell_object(who,CYN"\n白衣老人见你闯了进来，突然圆睁双眼：你怎么敢闯进我的屋子？！\n"NOR);
		tell_object(who,CYN"\n你只觉得眼前白影一闪，一股大力将你推出了屋子。\n"NOR);
		who->set_temp("lnwm/不可进",1);
		who->move( __DIR__"shanpo");
		tell_object(who,RED"\n\n只听老人的声音从屋中传来：下次再敢闯进我的屋子，就得死！！！！\n\n"NOR);
		who->unconcious();
		return;
	}
}
    


