/* lingyang.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980330
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980330
 */

inherit NPC;

void create()
{
    set_name( "高鼻羚羊",({ "ling yang","yang","oryx" }) );
    set( "long","一只生活在沙漠中的羚羊，体形很大，鼻高而鼓账，它的角具有\n"
"宝贵的药用价值。\n" );
    set( "race","野兽" );
    set( "age",5 );

    set( "str",30 );
    set( "dex",300 );
    set( "int",25 );
    set( "con",50 );

    set( "max_qi",500 );
    set( "max_jing",500 );

    set( "limbs",({ "头部","身体","前蹄","后蹄","尾巴","角" }) );
    set( "verbs",({ "hoof"}) );

    setup();
    carry_object( __DIR__"obj/lyjiao" );
}




