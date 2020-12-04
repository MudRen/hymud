/* sichou.c  丝绸
 * from XO Lib
 * a obj of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ITEM;

#include <ansi.h>

void create()
{
    set_name( YEL"丝绸"NOR,({"si chou","sichou","silk" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","用蚕丝织成的一种织物，可以做衣服。\n" );
        set( "unit","匹" );
        set( "value",7000 );
    }
    setup();
}
