/* camel.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980406
 */

#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "����",({ "luo tuo","camel","luotuo" }) );
    set( "long","һֻ���������գ����νý����ñ��ܡ�\n" );
    set( "race","Ұ��" );
    set( "age",5 );

    set( "str",100 );
    set( "dex",200 );
    set( "int",25 );
    set( "con",50 );

    set( "max_qi",500 );
    set( "max_jing",500 );

    set( "limbs",({ "ͷ��","����","ǰ��","����","β��" }) );
    set( "verbs",({ "hoof"}) );

    set( "can_be_ride",1 );
    setup();
}


