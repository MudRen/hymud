 inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"残棋"NOR, ({ "残棋","canqi" }));
                 set("long",
"骤然看来，这是一副残局，但仔细观摩，发觉黑棋绝处逢生，另有奥妙，你似乎能从中领悟出一些道理。\n"
               );  
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "局");
                set("value", 70);
                set("material", "wood");
                set("no_shown",1);
                set("no_get",1);
                set("no_drop",1);
                set("skill", ([
                        "name":                 "finger",    
                        "exp_required": 0,              
                        //"sen_cost":             0,     
                        "difficulty":   100,     
                        "max_skill":    100              
                ]) );
        }
    
} 
