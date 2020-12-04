#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "货船", ({ "boat" }) );
    set("unit", "只");
    set("value",0);
    set("no_get",1);
    set("long","白云岛跟南海贸易来往的商船，除了运货当然也可以航海（sail）\n");
    set_weight(150000);
    
} 
void init()
{
    add_action("do_sail","sail");
} 
int do_sail(string arg)
{
    message_vision(HIY"$N坐在货船上向海中驶去．．．\n\n\n\n\n"NOR,this_player());
    tell_object(this_player(),HIY"过了很久，终于到了岸边。\n\n\n\n\n"NOR);
    this_player()->move("/d/baiyun/beach1");
//  destruct(this_object());
    return 1;
}      
