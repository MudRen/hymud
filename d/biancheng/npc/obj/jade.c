#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"碧玉"NOR, ({ "jade" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("value", 2000);
            set("material", "jade");
            set("long", "晶莹无瑕的碧玉，本是太平王王冠上的，价值连城。\n");
          } 
    
}       
