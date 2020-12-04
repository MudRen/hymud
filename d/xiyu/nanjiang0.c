/* nanjiang0.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit ROOM;

void create()
{
    set( "short","ɳĮ" );
    set( "long",@LONG
������һƬɳĮ�ϣ����°�͹�����ɳ�������������ϼ������ѡ�ӭ����
���ƵĿ��ɳ�����ҵĴ�أ�������쳤���ֱۺ����������ƣ�ǧ����ǰ�ɿ���
�ĺӴ�����ɫ��ɽ�ͣ�����ɫ����գ�������ʯ�Ļ�Į����һ�еľ���ʹ��е�
�е��������ԡ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "north" : __DIR__"guizi",
        "south" : __DIR__"nanjiang1",
        "west"  : __FILE__,
        "east"  : __FILE__,
        "southeast" : __DIR__"nanjiang"+random(3),
        "northwest" : __DIR__"nanjiang"+random(3),
        "northeast" : __DIR__"nanjiang"+random(3),
        "southwest" : __DIR__"nanjiang"+random(3),
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    int current_water;
    
    me = this_player();
    current_water = me->query( "water" );
    if( current_water == 0 ) 
    {
        return notify_fail( "������ȱˮ���أ���Ҳ�����������ˡ�\n" );
    }
    if( current_water <= 5 )
    {
        write( RED"����ˮ�ֵĹ�����������е���Ҫ�����ˡ�\n"NOR );
        me -> set( "water",0 );
        if( random( 3 ) == 0 )
        {
            write( RED"��ֻ������ǰһ��������ת������\n"NOR );
            call_out( "die",1,me );
            return 1;
        }
    }
    else
    {
//�������յ�ʱ��ˮ�����ļ��١�
        if ( !me->query_temp_marks( "is_riding" ) )  
            me -> add( "water",-10 );
        else
            me -> add( "water",-5 );
    }
    return ::valid_leave( me,dir );
}

void die( object me )
{
    me -> die();
}
