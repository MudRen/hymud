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
    set_name( "Сʯͷ",({ "xiao shi tou","stone","shitou" }) );
    set_weight( 1000 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","��" );
        set( "material","stone" );
        set("wield_msg", "$N����һ��$n��\n");
        set("unwield_msg", "$N�������е�$n��\n");
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
        return notify_fail("��Ҫ��˭?\n");
    if( environment( me )->query( "have_tujiu" ) )
    {
        if( my_force < 700 )
        {
            write( "��˫�ּн�Сʯͷ���þ�һ��������ʯͷû�ɶ�Զ�͵���������\n" );
            destruct( this_object() );
            return 1;
        }
        else if( my_force > 1000 )
        {
            write( "������ָ����һ��Сʯͷ������һ����ʯͷ������֮������ͺ�շ�ȥ��\n" );
            write( "ֻ��ͺ��һ���ҽУ������ŵ�����ɳ���ϡ�\n" );
            environment( me ) -> add( "have_tujiu",-1 );
            me -> add( "force",-100 );
            ob = new( __DIR__"tujiu1.c" );
            ob -> move( environment( me ) );
            destruct( this_object() );
            return 1;
        }
        else
        {
            write( "����ָ��סСʯͷ����׼ͺ��ʹ��һ�䣬ʯͷ�ɿ�ķ��˳�ȥ��\n" );
            write( "ֻ��ͺ��һ���ҽУ������ŵ�����ɳ���ϡ�\n" );
            environment( me ) -> add( "have_tujiu",-1 );
            me -> add( "neili",-100 );
            ob = new( __DIR__"tujiu1" );
            ob ->move( environment( me ) );
            destruct( this_object() );
            return 1;           
         }   
    }
    else 
        return notify_fail( "�����Χû��ͺ�տɴ�\n" );
}
