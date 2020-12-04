/* shamo3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

#define DIR   __DIR__"shamo7"
//define the correct way

#include "shamo.h"

public int month;
mapping *exit = ({
    ([ "forward" : __DIR__"shamo7",
         "right" : __FILE__,
         "backward":__DIR__"shamo2",
         "left" : __FILE__,
       ]),
    ([ "right" : __DIR__"shamo7",
         "backward" : __FILE__,
         "left":__DIR__"shamo2",
         "forward" : __FILE__,
       ]),
    ([ "backward" : __DIR__"shamo7",
         "left" : __FILE__,
         "forward":__DIR__"shamo2",
         "right": __FILE__,
       ]),
    ([ "left" : __DIR__"shamo7",
         "forward" : __FILE__,
         "right":__DIR__"shamo2",
         "backward" : __FILE__,
       ]),
});


void create()
{

    set( "short","��ɳĮ" );
    SetLong();
    set( "exits",exit[random( 4 )] );
    
    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    eventClear( this_object() );
    SetLong();
    remove_call_out( "check_month" );
    call_out( "check_month",1 );
    remove_call_out("greet_me");
    call_out( "greet_me",1,this_player());
}

//�й�ɳĮ������Ĵ�����������У���������ɳ��--������磬��ɳ����
//ǰ��һ�㷢����6��7�·ݣ�����4��5�·ݡ�д�ĳ���û�б�Ҫ��ô������
//ͳһ����ɳ������4-7�·ݷ�����
void check_month()
{   
    month = localtime( time_tick )[ LT_MON ] + 1;
    if( month > 7 || month <4  )
        call_out( "before_storm",10 );    //4-7����ɳ��
    else 
        call_out( "check_month",100 );    //�����·�û��
}

void before_storm()
{
    message( "vision",RED"ͻȻ��о������µ�ɳ�����𶯡�����������\n"NOR,this_object() );
    message( "vision",RED"��̧ͷ����������һ�£��㷢����Զ���Ŀ���һ�ź�ɫ��"
"�����ڲ�ͣ\n��Ť���ţ��������о�����һ˿����֮�ס�����\n"NOR,this_object() );
    call_out( "check_storm",10 );
}

//�ж�ɳ���Ƿ��ƶ�������������2/3�ĸ��ʻ�
void check_storm()
{
    if( random( 60 ) >40 )
    {
        message( "vision",YEL"���ź�ɫ�Ķ����ڿ��������˰���󣬽�����Զ���"
"ȥ�ˡ�\n"NOR,this_object() );
    call_out( "check_month",450 );
    }
    else
    {
        message( "vision",RED"ֻ���������������ž޴������������������ƶ�"
"������ӭ�����\n��ɳ�ӣ��Ե���������˫�ۡ�\n"NOR,this_object() );
        call_out( "sand_storm",5 );
    }
}

//����ɳ���Ĺ��̣�
void sand_storm()
{
    object *all,*inv;
    int i,j,rannum;

    message( "vision",RED"�����ŷ�ĺ�Х����ɳ�ӱ����˰�գ��γ�������ʽ����"
"��Բ����\n"NOR,this_object() );
    all = all_inventory( this_object() );
    for ( i=0; i<sizeof(all); i++ )
    {
        if ( !living( all[i] ) && !userp( all[i] ) )
        {
            destruct( all[i] );             //����living,dest��
            continue;
        }
        if ( !userp( all[i] ) ) 
        {
            all[i]->die();                  //��ppl,ֱ��die
            continue;
        }
        else
        {
            inv = all_inventory( all[i] );    //ppl�����
            for ( j=0;j<sizeof( inv );j++ ) 
            {                                 //���϶���ȫû��
                inv[j] -> move( environment( all[i] ) );
                destruct( inv[j] );
            }   
            tell_object( all[i],"��о���һ�ɾ޴�����������е��˰�գ�Ȼ�����ֵ���������\n" );
            rannum = random( 100 );
            if( rannum >97 )
            {
                switch( random( 10 ) )
                {
                    case 1:                    //�ε�¥�����桡��/1000�ļ���
                        all[i] -> move( __DIR__"loulan1" );    
                        all[i] -> unconcious();          
                        break;
                    default:                   //ֱ��������18/1000�ļ���
                        all[i] -> die();
                       break;
                }
            }  
            else if( rannum >89 )              //���ε����ޡ�7/100�ĸ���
            {
                all[i] -> move( __DIR__"lvzhou" );
                all[i] -> unconcious();
            }
            else                                //ɳĮ�е��κ�һ��room 9/100�ĸ���
            {
                all[i] -> move( __DIR__"shamo" + rannum/9 );
                all[i] -> unconcious();
            }
        }
        message( "vision","ͻȻ�ӿ��е���һ������˵��ϡ�\n",
environment( all[i] ),({ all[i] }) );
    }
    call_out( "check_month",300 );
}
