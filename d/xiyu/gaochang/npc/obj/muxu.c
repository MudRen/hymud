/* muxu.c  ��ޣ
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
    set_name( HIY"��ޣ"NOR,({"mu xu","muxu","clove" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","һ�ֲ�ҩ\n" );
        set( "unit","��" );
        set( "value",3000 );
    }
    setup();
}
