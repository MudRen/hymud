/* fanwen_book.c  �����鼮
 * from XO Lib
 * a obj of gaochang
 * created by hydra 19980524
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980524
 */

inherit ITEM;

#include <ansi.h>

void create()
{
    set_name( "�����鼮",({"fanwen shu","book","shu" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","һ�������鼮\n" );
        set( "unit","��" );
        set( "value",800 );
    }
    setup();
}
