/* zhetang.c  ����
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
    set_name( "����",({"zhe tang","tang","sugar" }) );
    set_weight( 100 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "long","�Ӹ����������������ǣ�ζ��\n" );
        set( "unit","��" );
        set( "value",1000 );
    }
    setup();
}
