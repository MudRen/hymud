/* maoniu.c ��ţ
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
    set_name( "��ţ",({ "mao niu","niu","sheep","yak" }) );
    set( "long","һֻ��ţ�����׳��\n" );
    set( "race","Ұ��" );
    set( "age",5 );

    set( "str",50 );
    set( "dex",40 );
    set( "int",25 );
    set( "con",30 );

    set( "max_qi",400 );
    set( "max_jing",400 );

    set( "limbs",({ "ͷ��","����","ǰ��","����","β��" }) );
    set( "verbs",({ "hoof"}) );

    setup();
}


