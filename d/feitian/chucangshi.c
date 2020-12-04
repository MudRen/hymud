//shufang.c
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","储藏室");
	set("long",@LONG
这里是活心流的储藏室，里面乱七八糟的放着杂物。蜘蛛网到
处都是，你忍不住想帮忙整理一下。这里有条密道可以进入。
(enter midao)
LONG);
	set("exits",([
		"south" : __DIR__"houting",
		//"down" : __DIR__"pubu",
	]));
	if (random(5) > 3)
	set("objects",([
                __DIR__"obj/ftyj-book" : 1,
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("book_count", 1);
	setup();
}
void init()
{
	add_action("do_zhengli", "zhengli");
	    add_action("do_enter", "enter");
}

int do_zhengli()
{

	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(10) == 1))
	{
		message_vision(
HIY"$N认真的埋头工作，无意中在杂物中翻到了一本书。\n"NOR,me);
                ob=new("/d/feitian/obj/ftyj-book.c");
		ob->move(me);
message("channel:rumor", HIW"【奇遇】某人："+this_player()->query("name")+"找到了飞天御剑流的御剑流宝典下册。\n"NOR, users());
		add("book_count", -1);
	}
	else if ((query("book_count") > 0) && (random(10) == 2))
	{
		message_vision(
HIY"$N认真的埋头工作，无意中在杂物中翻到了一本书。\n"NOR,me);
                ob=new("/d/feitian/obj/ftyj-book2.c");
		ob->move(me);
message("channel:rumor", HIC"【奇遇】某人："+this_player()->query("name")+"找到了飞天御剑流的御剑流宝典上册。\n"NOR, users());
		add("book_count", -1);
	}

	else if ((query("book_count") > 0) && (random(5) == 3))
	{
		message_vision(
HIY"$N认真的埋头工作，无意中在杂物中翻到了一本书。\n"NOR,me);
                ob=new("/d/feitian/obj/ft-book.c");
		ob->move(me);
message("channel:rumor", MAG"【奇遇】某人："+this_player()->query("name")+"发现了飞天御剑流历代相传的御剑流宝典。\n"NOR, users());
		add("book_count", -1);
	}
	else message_vision(
HIY"$N辛辛苦苦整理了好半天，弄的灰头土脸的，但还是一样的乱。\n"NOR,me);
	return 1;
}


int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="midao" ) 
       {
         tell_object(this_player() , "你要去哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "飞天御剑流")
{
     message_vision("$N这是飞天御剑流的密道,你不认识路!\n",  ob);
    return 1;
}



    ob->move("/d/feitian/pubu") ;
    tell_object(ob, BLU "你看清了路，来到了后山!\n" NOR ) ;
    return 1 ;
}