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
    set_name( "受伤的秃鹫",({ "tu jiu","vulture","tujiu" }) );
    set( "long","一只受伤的秃鹫，正躺在地上。\n" );
    set( "race","野兽" );
    set( "age",1 );

    set( "str",30 );
    set( "dex",60 );
    set( "int",25 );
    set( "con",20 );

    set( "qi",-1 );
    set( "gin",-1 );
    set( "sen",-1 );

    set( "limbs",({ "头部","身体","翅膀","脚爪" }) );
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

    write( "你从秃鹫的身上撕下一块肉，连毛带血嚼了起来。\n ");
    me->add( "food",100 );
    this_object() -> add( "remain",-1 );
    if( !this_object()->query( "remain" ) ) 
    {
        write( "你终于把秃鹫吃的干干净净。\n" );
        destruct( this_object() );
    }
    return 1;
}

int do_suck( string arg )
{
    object me;
    me = this_player();

    if( !arg && arg !="tu jiu" && arg != "vulture" && arg != "tujiu" ) return 0;

    write( "你把嘴巴凑到秃鹫的伤口上，拼命地吸了起来。\n" );
    me -> add( "water",50 );
    this_object() -> add( "remain",-1 );
    if( !this_object()->query( "remain" ) ) 
    {
        write( "秃鹫已经被你吸的只剩下一个干枯的外壳。\n" );
        destruct( this_object() );
    }
    return 1;
}

