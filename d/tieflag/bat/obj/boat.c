#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "帆船", ({ "boat" }) );
    set("unit", "块");
    set("value",0);
    set("no_get",1);
    set("long","一只精巧的帆船，可以用来航海（sail）\n");
    set_weight(150000);
    
} 
void init()
{
    add_action("do_sail","sail");
} 
int do_sail(string arg)
{
    message_vision(HIY"$N坐在帆船上向海中漂去．．．\n"NOR,this_player());
    tell_object(this_player(),HIY"过了很久，终于到了岸边。\n"NOR);
    this_player()->move("/d/tieflag/bat/fchuan");
//  destruct(this_object());
    return 1;
}      
