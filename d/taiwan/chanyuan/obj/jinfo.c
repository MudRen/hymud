
 
inherit ITEM;

#include <ansi.h>

void create()
{
   set_name(HIY"金佛"NOR, ({"jin fo","fo"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个小金佛，看起来很值钱。\n");
                set("unit", "个");
                set("value", 10000);
                set("no_sell",1);
                set("nogive_player",1);
                set("bai_butan_quest",1);
        }
}

