// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(CYN"����"NOR, ({"yu7"}));
    set_weight(30000);
    set("long", "һ���ܴ�ĺ��Σ�\n");
        set( "unit", "��" );


        set( "value", 700 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
