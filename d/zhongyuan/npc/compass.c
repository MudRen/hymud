/* stone.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980325
 */

inherit ITEM;

void create()
{
    set_name( "ָ����",({ "zhinan zhen","compass" }) );
    set_weight( 200 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","��" );
        set( "long","һ��ָ���룬���й��Ŵ����ǻ۵Ľᾧ��\n" );
        set( "value",5000 );
        set( "material","iron" );
    }

    set( "can_use",10 );
    setup();
}

void init()
{
    add_action( "do_use","use" );
}

int do_use( string arg )
{
    string south;
    object me;
    me = this_player();
    if( arg != "zhinan zhen" && arg != "compass" ) return 0;
    if( query( "can_use" )<1 ) return notify_fail( "���ָ�����Ѿ��������ˡ�\n" );
    if( environment( me )->query( "outdoors" ) != "desert" )
        return notify_fail( "�����ֵط��㻹�õ���ָ�������жϷ�����?\n" );
    if( south = environment( me )->query_south( 0 ) )
        write( "���ָ����,������������ָ��" + south +"����\n" );
    else
        write( "������ط�ָ����û���á�\n" );
    if ( environment( me )->query( "�ų�" ) )
        add( "can_use",-2 );
    else 
        add( "can_use",-1 );
    return 1;
}


