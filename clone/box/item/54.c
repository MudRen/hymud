// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name( RED"��Ϻ"NOR, ({"yu5"}) );
    set_weight( 30000 );
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
        set( "long", @LONG
һֻ��Ϻ�������ʣ������ɿڣ��Ǻ��ϵ��ز���
LONG
        );
        set( "unit", "ֻ" );


        set( "value", 500 + random( 600 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
    }
}

int do_eat( string arg )
{
    return notify_fail("�⻹�����ģ�ֻ����è�ſϳԡ�\n");
}
