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
    set_name( HIW"�����"NOR,({ "lingyang jiao","","horn","jiao" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","ֻ" );
        set( "long","����һֻ׳������ǣ��ʵ�͸������Ө����ҩЧ���ѡ�\n" );
        set( "value",10000 );
    }

    setup();
}


