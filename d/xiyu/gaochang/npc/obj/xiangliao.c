/* xiangliao.c  香料
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
    set_name( HIY"香料"NOR,({"xiang liao","spicery" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","香料，清香宜人。\n" );
        set( "unit","棵" );
        set( "value",10000 );
    }
    setup();
}
