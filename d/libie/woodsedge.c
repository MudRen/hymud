 // Room: woodsedge.c --- by MapMaker
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "树林尽头"); 
        set("long", @LONG
你左拐右拐，走到了小树林的尽头，潺潺的小溪又汩汩地冒了
出来，静静地流淌着，林子中虽然看不到太阳，树梢间还是有阳光
照射而下，一两只蹦蹦跳跳的小野兔好奇地望着你。路边空地有几
处黄土，借着微光，不远处似乎有一间破陋而废旧的小木屋。
LONG); 
        //{{ --- by MapMaker
        set("type","forest");
        set("exits",([
        "south":__DIR__"woods1",
        "north":__DIR__"cabin",
        ]) );
        set("outdoors", "libie");
        set("coor/x",70);
        set("coor/y",230);
        set("coor/z",0);
        //}} 
        setup(); 
} 
void init()
{
        add_action("do_look","look");
        add_action("do_dig","dig");
} 
int do_look(string arg)
{
        if(arg!="黄土" && arg!="soil" && arg != "huangtu") {
                return 0;
        }
        tell_object(this_player(),"一掊黄土，掩埋了多少豪杰英雄。\n");
        return 1;
}   
        
int do_dig(string arg)
{
        object me,delve;
        me=this_player();
        
        if(arg!="黄土" && arg!="soil" && arg != "huangtu") 
                return notify_fail("你要挖什么？\n");
        delve=present("delve",this_object());
        if(objectp(delve)&&(!userp(delve)))
                return notify_fail("土坑已经挖好了。\n");
        if(me->query("qi")<100)
                return notify_fail("你现在气血太少，无力挖坑。\n");
        me->add("qi",-100);
        message_vision(YEL"$N花了好大力气，总算挖了一个土坑。\n"NOR,me);
        delve=new(__DIR__"obj/delve");
        delve->move(this_object());
        return 1;
}    
