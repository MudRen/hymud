/* congrong.c
 * from XO Lib
 * a widelife of desert
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980409
 */

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name( HIY"����"NOR,({ "cong rong","","congrong" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","��" );
        set( "long","����һ��ɳĮ���е�ֲ�Ҳ��һ�������ҩ�ģ�����Ϊ��ɳĮ�˲Ρ���\n" );
        set( "value",100 );
        set( "food_remaining",5 );
        set( "food_supply",60 );
        set( "eat_msg","$N����$nҧ��һ�ڣ�ֻ������������˻�����\n" );
        set( "end_msg","$N���ڰ�ʣ��$n�Եĸɸɾ�����\n" );
    }

    setup();
}

