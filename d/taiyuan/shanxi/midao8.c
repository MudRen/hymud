#include <ansi.h> 
inherit ROOM;
void create() 
{ 
    set("short", "密室"); 
    set("long", @long
这间密室非常窄小，并且十分潮湿，奇怪的是，密室非常的明亮，
透过光线，这里的一切清清楚楚，西面墙角有一个箱子，站在箱子
上，你可以触摸到屋顶的石块(rock)。
long 
    ); 
    set("exits", ([ 
        ])); 
	set("item_desc", ([
                "箱子": "石头雕刻的箱子，你可以爬上去。\n",
                "box": "石油雕刻的箱子，你可以爬上去。\n" ,
                "石块": "一块与众不同的石块，似乎可以移动(move)。\n",
                "rock" : "一块与众不同的石块，似乎可以移动(move)。\n",
        ]) );
    set("indoors","shanxi"); 
        set("coor/x",-480);
        set("coor/y",-260);
        set("coor/z",50);
        setup(); 
} 
void init()
{
add_action("do_climb","climb");
add_action("do_move","move");
}
int do_climb(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "箱子" || arg == "box" || arg == "up" )
        {
        	me = this_player();
        	message_vision("$N看看了对面的箱子，手脚并用，慢慢的爬了上去。\n", me);
        	me->set_temp("marks/climb_box",1);
        	write("现在可以摸到石块了。\n");
       	return 1;
        }
}

int do_move(string arg)
{
        object room;
        object me;
        
        me = this_player();
        
        if(!arg || arg=="")
        {
                write("你要移动什么？\n");
                return 1;
        }
        if( arg == "石块" || arg == "rock" )
        {
        	if(!me->query_temp("marks/climb_box"))
        		return notify_fail("石块有点高，你触摸不到。\n");
                message_vision("$N伸手慢慢的把石块移动开，露出了一个洞，$N狼狈不堪地爬了上去。\n",me);
                me->delete_temp("marks/climb_box");
        	room = find_object(__DIR__"alou");
        	if(!objectp(room)) room = load_object(__DIR__"alou");
        	message("vision","地上的石块突然被移开，"+me->name()+"从下面狼狈地爬了上来。\n",room);
        	me->move(room);
       	return 1;
        }
}