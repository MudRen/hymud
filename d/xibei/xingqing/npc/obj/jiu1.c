//jiu1.c.фоля╬ф
//date:1997.8.27
//by dan     

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID; 

void create()
{
        set_name(MAG"фоля╬ф"NOR, ({"putao jiu", "jiu"}));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "р╩╦Жв╗цесцю╢в╟фоля╬ф╣д╢иф©║ё\n");
                set("unit", "ф©");
                set("value", 1000);
                set("max_liquid", 100);
        }
        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "фоля╬ф",
                "remaining": 30,
                "drunk_apply": 40,
        ]));
}  

void init()
{
        this_object()->delete("value");
        add_action("do_drink","drink");
}

