/* jibei cao.c
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
    set_name( HIY"吉贝草"NOR,({"jibei cao","jibeicao" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","产于印度的一种植物，可以用来做衣服。\n" );
        set( "unit","棵" );
        set( "value",300 );
    }
    setup();
}
