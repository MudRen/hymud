/* tujiu1.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980325
 */

inherit NPC;

void create()
{
    set_name( "���˵�ͺ��",({ "tu jiu","vulture","tujiu" }) );
    set( "long","һֻ���˵�ͺ�գ������ڵ��ϡ�\n" );
    set( "race","Ұ��" );
    set( "age",1 );

    set( "str",30 );
    set( "dex",60 );
    set( "int",25 );
    set( "con",20 );

    set( "qi",-1 );
    set( "gin",-1 );
    set( "sen",-1 );

    set( "limbs",({ "ͷ��","����","���","��צ" }) );
    set( "verbs",({ "claw","poke" }) );

    set( "remain",5 );
    
    setup();
}

void init()
{
    add_action( "do_eat","eat" );
    add_action( "do_suck",({ "suck","xi" }) );
}

int do_eat( string arg ) 
{
    object me;
    me = this_player();

    if( !arg && arg != "tu jiu" && arg != "vulture" && arg != "tujiu" ) return 0;

    write( "���ͺ�յ�����˺��һ���⣬��ë��Ѫ����������\n ");
    me->add( "food",100 );
    this_object() -> add( "remain",-1 );
    if( !this_object()->query( "remain" ) ) 
    {
        write( "�����ڰ�ͺ�ճԵĸɸɾ�����\n" );
        destruct( this_object() );
    }
    return 1;
}

int do_suck( string arg )
{
    object me;
    me = this_player();

    if( !arg && arg !="tu jiu" && arg != "vulture" && arg != "tujiu" ) return 0;

    write( "�����ʹյ�ͺ�յ��˿��ϣ�ƴ��������������\n" );
    me -> add( "water",50 );
    this_object() -> add( "remain",-1 );
    if( !this_object()->query( "remain" ) ) 
    {
        write( "ͺ���Ѿ���������ֻʣ��һ���ɿݵ���ǡ�\n" );
        destruct( this_object() );
    }
    return 1;
}

