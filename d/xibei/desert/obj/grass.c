/* grass.c
 * from XO Lib
 * a widelife of desert
 * created by hydra 19980406
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980406
 */

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( GRN"���"NOR,({ "qing cao","","grass" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","��" );
        set( "long","һС����ݡ�\n" );
        set( "value",-1 );
    }

    setup();
}


