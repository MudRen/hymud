// red.c
// by dicky

#include <ansi.h>

inherit ITEM;

void create()

{
        set_name(HIR"红货"NOR, ({"prize"}));
        set("unit", "包");
        set("long", "一包从来往镖队那里抢来的红货，拿给黑衣人应该就可以得到奖励了。\n");
        set("value", 2000);
        setup();
}
