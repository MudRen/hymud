#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name(RED"女儿红"NOR, ({"nver hong", "hong", "nver"}));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个专门用来装女儿红的酒坛子。\n");
                set("unit", "坛");
                set("value", 1000);
                set("max_liquid", 100);
        }
        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "女儿红",
                "remaining": 30,
                "drunk_apply": 40,
        ]));
}
void init()
{
        this_object()->delete("value");
        add_action("do_drink","drink");
}

