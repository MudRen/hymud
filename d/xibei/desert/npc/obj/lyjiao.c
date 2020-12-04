/* lyjiao.c
 * from XO Lib
 * the horn of oryx
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980330
 */

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( HIW"羚羊角"NOR,({ "lingyang jiao","","horn","jiao" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","只" );
        set( "long","这是一只壮年羚羊角，质地透明，晶莹如玉，药效极佳。\n" );
        set( "value",10000 );
    }

    setup();
}


