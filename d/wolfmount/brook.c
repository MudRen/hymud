#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "浣花溪"); 
        set("long", @LONG
一道清澈见底的泉水从山中溅落下来，嘈嘈切切错杂弹地，大珠小珠似雨打玉
盘，两旁山花烂漫，溪水中各色缤纷的花瓣随着溪水静静地流淌，一切美丽如画。
泉水浅浅可行，逆流而上，可看到不远处白云深处的泉水源头有个湖泊。
LONG); 
        set("type","waterbody");
        set("outdoors", "wolfmount");
        set("exits",([
                "southeast":__DIR__"brook4",
                "southwest":__DIR__"brook3",
        ]) );
        set("objects",([
                __DIR__"npc/xiaoling":1,
                __DIR__"npc/xiaorou":1,
        ]) ); 
    set("coor/x",-720);
    set("coor/y",-710);
    set("coor/z",60);
        setup();
} 
void init()
{
        add_action("do_look", "look");
} 
void conch_notify()
{
        object me;
        int lel;
        me = this_player();
        lel = me->query("kar");
        if(random(100) < lel) 
        {
                remove_call_out("fog_disappear");
                call_out("fog_disappear",3,me);
        }
   else 
        {
                message_vision("许久许久，雾气依旧，什么都没有发生。\n",me);
        }
        return;
} 
int valid_leave(object me, string dir)
{
	if ( objectp(present("xiaorou", environment(me))) && 
		dir == "southwest")
		return notify_fail("嬉小柔拦住了你的去路。\n");

	if ( objectp(present("xiaoling", environment(me))) && 
		dir == "southwest")
		return notify_fail("嬉小玲拦住了你的去路。\n");


me->set_temp("marks/wolf_blow_conch",1);
	return ::valid_leave(me, dir);
} 

int do_look(string arg)
{
        object  me;
        me = this_player();
        if( arg == "southwest") 
        {
                message_vision(HIY"$N探头探脑的向西南方看了看．．．．．．\n"NOR, me);
                tell_object(me,"那边雾气弥漫，什么都看不到。\n"); 
                return 1;
        }
        return 0;
}  
