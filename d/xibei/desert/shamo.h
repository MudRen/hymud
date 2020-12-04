/* shamo.h
 * from XO Lib
 * an include file ,define some function for all room of this desert
 * created by hydra 19980328
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

#include <ansi.h>
#include <localtime.h>
#include <command.h>

inherit ROOM;

public int time_tick;
public int clock;
void rescue( object me );

//����ppl����room�����г��ڡ�
mapping query_exit()
{
    return environment( this_player() )->query( "exits" );
}


//��������������ͨ��query_exit()�õ���mapping��key&value
string *query_value()
{
    return values( query_exit() );
}

string *query_key()
{
    return keys( query_exit() );
}

//����ppl����room�Ĵ���south�ĳ���,����������������
string query_south( int flag )
{
    string *value,*key;
    
    value = query_value();
    key = query_key();
//flag=0 ��compass�жϣ������Ϸ������ܴų���Ӱ��
//flag=1 ��̫�����жϣ������Ϸ�
//flag=2 ���������жϣ���������
    switch ( flag )
    {
        case 0:
            if( !environment( this_player() )->query( "�ų�" ) )
                switch ( key[ member_array( DIR,value ) ] )
                {
                    case "forward":
                        return "left";
                        break;
                    case "right":
                        return "forward";
                        break;
                    case "backward":
                        return "right";
                        break;
                    case "left":
                        return "backward";
                        break;
                }
            else
                return key[ random( 4 ) ];
            break;
        case 1:
            switch ( key[ member_array( DIR,value ) ] )
            {
                case "forward":
                    return "left";
                    break;
                case "right":
                    return "forward";
                    break;
                case "backward":
                    return "right";
                    break;
                case "left":
                    return "backward";
                    break;
            }
            break;
        case 2:
            switch ( key[ member_array( DIR,value ) ] )
            {
                case "forward":
                    return "right";
                    break;
                case "right":
                    return "backward";
                    break;
                case "backward":
                    return "left";
                    break;
                case "left":
                    return "forward";
                    break;
            }
            break;
    }
}


/* the following are some functions for action "look" to call
 * do_look()   action of look
 * change_exit()  change exits after 5 second if you found a real lvzhou
 */
int do_look( string dir )
{
    object me;
    string old_dir;
    me = this_player();

//arg Ϊ����(right��left)ʱ�п��ܲ���������¥�����ʵս����ߵĻ�����
//������������ĸ���Ҳ��
    if( dir == "forward" || dir == "backward" || dir == "left" || dir == "right" )
    {
        switch ( random( 5 ) )
        {
            case 0:
                write( "�������ȥ��ֻ��" + dir + "����ʮ�����⣬һƬ�����������²���\n" );
                write( "���ԣ�����һƬ���֣��ּ�յ���¶��һ�������Ƿ��ݣ������ɹ�\n" );
                write( "���ĻҰ�ɫӰ����\n" );
//����������Ϊ��ļ���Ϊ combat_exp <10 k ʱ1% ,combat_exp >1M �� 100%
                if( !random( 1000000/( (int)me->query( "combat_exp" )+10000 ) ) ) 
                {
                    old_dir = environment( me )->query( "exits/"+dir );
                    environment( me )->set( "exits/"+dir,__DIR__"lvzhou" );
                    call_out( "change_exit",5,environment( me ),old_dir,dir );
                }
                break;
            default:
                write( "�㼫ĿԶ��������֮�������˻�ɳ����������һ�\n" );
                break;
        }
        return 1;
    }

//��������Ҫ��д���ƣ�����������Ļ��жϷ���̫easy�ˣ����ڻ�û�����ʲô��
//�ģ�������ע�͵�
/* 
//���쿴̫���жϷ���
    if ( dir == "sun" )
    {
        if ( clock > 20 || clock < 5 )
        {
            write( "�����㵽����ȥ��̫������\n" );
            return 1;
        }
        message_vision( "$Ņͷ����һ��̫����\n",me );
        write( "����̫���������" + query_south( 1 ) + "�ࡣ\n" );
        return 1;
    }

//���Ͽ������жϷ���
    if ( dir == "star" )
    {
        if ( clock <21 && clock > 4 )
        {
            write( "�����Ŀ�ʲô���ǰ���\n" );
            return 1;
        }
        message_vision( "$Ņͷ����һ�����ǡ�\n",me );
        write( "���ڱ������������" + query_south( 2 ) + "�ࡣ\n" );
        return 1;
    }
*/

    return 0;
}

void change_exit( object room,string exit,string dir )
{
    room->set( "exits/"+dir,exit );
}

// the following are funtion to set a long description of room
// the long description changes per 60 seconds
void SetLong()
{

    string long;
    long = "������һƬããɳĮ��һ���޼ʣ�ֻ��һЩ¡���ɳ�𣬲��������Ӱ����\n";
    long += "ʹż����Щ���յĿݹǣ�����΢С�İ׹�Ҳ����������Χ�Ĳ�ã������������";
    long += "��\n�����ƺ�ֻ���ȿ����������Ļ��졣��ʱ����һ�����磬�ѻ�ɳ������";
    long += "��ƽ\n��ð�������̣�����ת��ɳĮ�Ϸ��ܡ�";
    time_tick = time()*60;
    clock = localtime( time_tick )[ LT_HOUR ];
    if( clock>10 && clock<14 )
    {
        long += "���������ֱ���������ǵ�����ǿ�ҵķ�\n��ʹ����۾��ܲ����,��о�";
        long += "�������ڵ�ˮ�ֺ���Ҫ��������Ƶġ�\n";
    }
    else if( clock>20 || clock<5 )
    {
        long += "�콥����������������һƬ��ڣ�˿��û\n����Ӱ��\n";
    }
    else
    {
        long += "����м�ֻͺ���������ţ�������Ѱ����\n��ɳĮ�е����ջ��ˣ���������";
        long += "�����\n";
    }
    set( "long",long );
}

//the following are functions to decrease water when walking in the desert
// and the event whick will happen when one's water equals to 0.
int valid_leave( object me,string dir )
{
    int current_water;
    
    me = this_player();
    current_water = me->query( "water" );
    if( current_water == 0 ) 
    {
        return notify_fail( "������ȱˮ���أ���Ҳ�����������ˡ�\n" );
    }
    if( current_water <= 20 )
    {
        write( RED"����ˮ�ֵĹ�����������е���Ҫ�����ˡ�\n"NOR );
        me -> set( "water",0 );
        if( random( 5 ) == 0 )
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
            me -> add( "water",-20 );
        else
            me -> add( "water",-10 );
    }
    
    //For ������¥ Hydra 1998/5/24
    if ( dir == me->query_temp("hydra/desert/lvzhou_dir") )
    {
        me->add_temp("hydra/desert/lvzhou_step",1);
        me->delete_temp("hydra/desert/lvzhou_dir");
        if(me->query_temp("hydra/desert/lvzhou_step") >=3)
        {
            me->move(__DIR__"lvzhou");
            me->delete_temp("hydra/desert/lvzhou_step");
            return notify_fail(YEL"���������������ڵ�����һƬ���ޣ�\n"NOR);
        }
    }
    else
    {
        me->delete_temp("hydra/desert/lvzhou_dir");
        me->delete_temp("hydra/desert/lvzhou_step");
    }
        
    return ::valid_leave( me,dir );
}

void die( object me )
{
    me -> die();
}

//the following function decrease water of players who are in the desert
// by 20 per localtime hours .
void DecWater( object me,int time )
{
    int current_time,current_water;

    current_time = time();
    current_water = me->query( "water" );
    if( environment( me )->query( "outdoors" ) == "desert" )
    {
        if( current_water == 0 ) 
        {
            write( RED"����������ȱˮ����ǰһ�ڡ� \n"NOR );
            me -> die();
            return;
        }
        if( current_water <= 20 )
        {
            write( RED"������ɳĮ�д���ʱ��̫����ˮ�ֵĹ�����������е���Ҫ�����ˡ�\n"NOR );
            me -> set( "water",0 );
            if( random( 5 ) == 0 )
            {
                write( RED"��ֻ������ǰһ��������ת������\n"NOR );
                me -> die();
            }
            else
                call_out( "DecWater",60,me,current_time );
        }
        else
        {
            call_out( "DecWater",60,me,current_time );
            if ( !me->query_temp_marks( "is_riding" ) )
                me -> add( "water",-20 );
            else
                me -> add( "water",-10 );
        }
    }
}

//���room��ķ�������Ʒ����init����á�
void eventClear( object env )
{
    object * inv;
    int i;
    inv = all_inventory( env );

    for ( i=0;i<sizeof( inv );i++ )
        if( !inv[i]->is_character() )
            destruct( inv[i] );
}

void greet_me( object me )
{
    string *exits = ({ "forward","backward","right","left", });
    string dir;
    dir = exits[random(sizeof(exits))];
    if ( !random(3) ) return;
    if ( environment(me) != this_object() ) return;
    write( GRN"����ϡ����"+dir+"����һƬ���̣�һ����С�ĺ�������Χ���ż���������\n"NOR);
    me -> set_temp("hydra/desert/lvzhou_dir",dir);
}

