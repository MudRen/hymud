// matouqin.c 马头琴
// Ffox 98-4-30 18:57

inherit ITEM;

void create()
{
    set_name( "马头琴", ({"matou qin", "qin"}));
    set_weight( 1000 );
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", query("name") + "西域的一种民间乐器。\n");
        set("unit", "把");
        set("value", 4500 );
    }
}

