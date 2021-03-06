/* stone.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980325
 */

#include <weapon.h>

inherit HAMMER;

void create()
{
    set_name( "小石头",({ "xiao shi tou","stone","shitou" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","块" );
        set( "material","stone" );
        set("wield_msg", "$N拿起一块$n。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
    }

    init_hammer( 5 );
    setup();
}

void init()
{
    add_action( "do_shoot","shoot" );
}

int do_shoot( string arg )
{
    object me,ob;
    int my_force;
    me = this_player();
    my_force = me->query( "force" );

    if( arg != "tu jiu" && arg != "tujiu" && arg != "vulture" ) 
        return notify_fail("你要射谁?\n");
    if( environment( me )->query( "have_tujiu" ) )
    {
        if( my_force < 700 )
        {
            write( "你双手夹紧小石头，用劲一弹，但是石头没飞多远就掉了下来。\n" );
            destruct( this_object() );
            return 1;
        }
        else if( my_force > 1000 )
        {
            write( "你用手指拈了一颗小石头，轻轻一弹，石头如离弦之箭，向秃鹫飞去。\n" );
            write( "只听秃鹫一声惨叫，扑腾着掉到了沙子上。\n" );
            environment( me ) -> add( "have_tujiu",-1 );
            me -> add( "force",-100 );
            ob = new( __DIR__"tujiu1.c" );
            ob -> move( environment( me ) );
            destruct( this_object() );
            return 1;
        }
        else
        {
            write( "你手指夹住小石头，照准秃鹫使劲一射，石头飞快的飞了出去。\n" );
            write( "只听秃鹫一声惨叫，扑腾着掉到了沙子上。\n" );
            environment( me ) -> add( "have_tujiu",-1 );
            me -> add( "neili",-100 );
            ob = new( __DIR__"tujiu1" );
            ob ->move( environment( me ) );
            destruct( this_object() );
            return 1;           
         }   
    }
    else 
        return notify_fail( "你的周围没有秃鹫可打。\n" );
}
