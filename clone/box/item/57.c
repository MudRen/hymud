// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"�з"NOR, ({"yu8"}));
    set_weight(30000);
    set("long", "һ�������з\n");
    set("unit", "��");


        set( "value", 800 + random( 800 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}

