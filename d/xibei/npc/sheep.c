/* sheep.c ����
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
    set_name( "����",({ "mian yang","yang","sheep" }) );
    set( "long","һֻ�������ڵ�ͷ�Բݡ�\n" );
    set( "race","Ұ��" );
    set( "age",5 );

    set( "str",20 );
    set( "dex",40 );
    set( "int",25 );
    set( "con",20 );

    set( "max_qi",200 );
    set( "max_jing",200 );

    set( "limbs",({ "ͷ��","����","ǰ��","���","β��" }) );
    set( "verbs",({ "hoof"}) );

    setup();
}


