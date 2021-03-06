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
    set_name( "野骆驼",({ "luo tuo","camel","luotuo" }) );
    set( "long","一只生活在沙漠中的野骆驼，体形矫健，擅奔跑。\n" );
    set( "race","野兽" );
    set( "age",5 );

    set( "str",100 );
    set( "dex",200 );
    set( "int",25 );
    set( "con",50 );

    set( "max_qi",500 );
    set( "max_jing",500 );

    set( "limbs",({ "头部","身体","前蹄","后蹄","尾巴" }) );
    set( "verbs",({ "hoof"}) );

    set( "can_be_ride",1 );
    setup();
}

void init()
{
    object me;
    me = this_player();
    call_out( "camel_greet",1,me );
    add_action( "do_kill",({ "kill","sha","fight","bihua" }) );
    add_action( "do_ride","ride" );
}

int do_kill( string arg )
{
    object me;
    me = this_player();

    if( !id(arg) ) return 0;
    add( "hydra/desert/kill_camel",1 );          //每杀一次加一
    call_out( "camel_escape",2,this_object() );
    return 0;
}

void camel_escape( object me )
{
    message_vision( HIY"野骆驼受到$N的攻击，吓的四下逃散了。\n"NOR,this_player() );
    destruct( me );
}

int do_ride( string arg )
{
    object me;
    me = this_player();

    if ( !id( arg ) ) return 0;
    if ( query( "friendship/"+me->query( "id" ) ) <= 20 )
    {
        message_vision( "$N想要骑上$n,但是$n身体一扭，走开了。\n",me,this_object() );
        return 1;
    }
    else 
        return 0;
}

void camel_greet( object me )
{
    me = this_player();
    if ( me->query( "hydra/desert/kill_camel" ) > 2 )   // 如果杀过三次骆驼，以后就没有机会再
    {                                                   // 接近任何骆驼
        message_vision( RED"野骆驼看见$N的到来，飞快地逃走了。\n"NOR,me );
        destruct( this_object() );
    }
    if ( query( "friendship/"+me->query( "id" ) ) > 20 )
        message_vision( CYN"野骆驼亲密地用鼻子蹭了一下$N的身体。\n"NOR,me );

}

int accept_object( object me, object obj )
{
    if ( obj->query( "id" ) != "qing cao" || me->query( "hydra/desert/kill_camel" ) > 3 )
// 后面这个条件是防止player利用add_action的问题，乘骆驼逃离之前把草给骆驼
    {
        message_vision( "野骆驼用鼻子闻了闻$n，又把头扭了开去。\n",me,obj );
        return 0;
    }
    else
    {
        message_vision( "野骆驼闻了一下$n，把$n吃了下去。\n",me,obj );
        add( "friendship/"+me->query( "id" ),10 );  // 加的友好度只对本object 有效，其他
        return 1;                                   // 骆驼没有用
    }
}


