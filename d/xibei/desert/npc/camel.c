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
    set_name( "Ұ����",({ "luo tuo","camel","luotuo" }) );
    set( "long","һֻ������ɳĮ�е�Ұ���գ����νý����ñ��ܡ�\n" );
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
    add( "hydra/desert/kill_camel",1 );          //ÿɱһ�μ�һ
    call_out( "camel_escape",2,this_object() );
    return 0;
}

void camel_escape( object me )
{
    message_vision( HIY"Ұ�����ܵ�$N�Ĺ������ŵ�������ɢ�ˡ�\n"NOR,this_player() );
    destruct( me );
}

int do_ride( string arg )
{
    object me;
    me = this_player();

    if ( !id( arg ) ) return 0;
    if ( query( "friendship/"+me->query( "id" ) ) <= 20 )
    {
        message_vision( "$N��Ҫ����$n,����$n����һŤ���߿��ˡ�\n",me,this_object() );
        return 1;
    }
    else 
        return 0;
}

void camel_greet( object me )
{
    me = this_player();
    if ( me->query( "hydra/desert/kill_camel" ) > 2 )   // ���ɱ���������գ��Ժ��û�л�����
    {                                                   // �ӽ��κ�����
        message_vision( RED"Ұ���տ���$N�ĵ������ɿ�������ˡ�\n"NOR,me );
        destruct( this_object() );
    }
    if ( query( "friendship/"+me->query( "id" ) ) > 20 )
        message_vision( CYN"Ұ�������ܵ��ñ��Ӳ���һ��$N�����塣\n"NOR,me );

}

int accept_object( object me, object obj )
{
    if ( obj->query( "id" ) != "qing cao" || me->query( "hydra/desert/kill_camel" ) > 3 )
// ������������Ƿ�ֹplayer����add_action�����⣬����������֮ǰ�Ѳݸ�����
    {
        message_vision( "Ұ�����ñ���������$n���ְ�ͷŤ�˿�ȥ��\n",me,obj );
        return 0;
    }
    else
    {
        message_vision( "Ұ��������һ��$n����$n������ȥ��\n",me,obj );
        add( "friendship/"+me->query( "id" ),10 );  // �ӵ��Ѻö�ֻ�Ա�object ��Ч������
        return 1;                                   // ����û����
    }
}


