/* tujiu.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980326
 */

inherit NPC;

void create()
{
    set_name( "ͺ��",({ "tu jiu","vulture","tujiu" }) );
    set( "long","һֻ�޴��ͺ�գ����ڿ���������Ѱ�����\n" );
    set( "race","Ұ��" );
    set( "age",1 );

    set( "str",100 );
    set( "dex",200 );
    set( "int",25 );
    set( "con",20 );

    set( "max_qi",500 );
    set( "max_jing",500 );

    set( "limbs",({ "ͷ��","����","���","��צ" }) );
    set( "verbs",({ "claw","poke" }) );

    setup();
}




