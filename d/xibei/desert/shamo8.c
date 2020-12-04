/* /shamo8.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980409
 * last modify add action lie
 * for more information ,see shamo5.c
 */

#define DIR   __DIR__"shamo9"
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : __DIR__"shamo9",
         "right" : __DIR__"shamo" + ( random( 5 )+5 ),
         "backward":__DIR__"shamo4",
         "left" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "right" : __DIR__"shamo9",
         "backward" : __DIR__"shamo"+( random( 5 )+5 ),
         "left":__DIR__"shamo4",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "backward" : __DIR__"shamo9",
         "left" : __DIR__"shamo" + ( random( 5 )+5 ),
         "forward":__DIR__"shamo4",
         "right": __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "left" : __DIR__"shamo9",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
         "right":__DIR__"shamo4",
         "backward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
});


void create()
{
    set( "short","��ɳĮ" );
    SetLong();

    set( "exits",exit[random( 4 )] );

    if ( random( 3 ) == 0 )
        set( "objects",([ /*sizeof() == 1*/
            __DIR__"npc/camel":1,
        ]) );

    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "do_lie","lie" );
    add_action( "do_look",({ "look","l" }) );
    eventClear( this_object() );
    SetLong();
    remove_call_out("greet_me");
    call_out( "greet_me",1,this_player() );
}

int do_lie( string arg )
{
    object me;
    me = this_player();

    if( arg ) return 0;
    if( me->is_fighting() )
        return notify_fail( RED"������ս���У�����������\n"NOR );
    if( me->is_busy() ) return notify_fail( "��������æ���ء�\n" );

    message( "vision",me->name() + "ͻȻ���쵹�£����ڵ���һ�������ˡ�\n",
        environment( me ),({ me }) );
    write( "���������ڵ��ϣ���ס��������ʼװ����\n" );
    me -> start_busy( 5 );
    remove_call_out( "tujiu_come" );
    call_out( "tujiu_come",5,me );
    return 1;
}

void tujiu_come( object me )
{
    object bird;
    int my_kee,my_sen,my_max_kee,my_max_sen;

    my_kee = me->query( "kee" );
    my_sen = me->query( "sen" );
    my_max_kee = me->query( "max_qi" );
    my_max_sen = me->query( "max_sen" );

    if( (my_kee/my_max_kee)*100 > 40 && (my_sen/my_max_sen)*100 > 40 
        || clock < 5 || clock > 20 || clock > 10 || clock < 14 )
    {
        message( "vision",me->name() + "�ڵ������˰��죬��ҡҡͷվ��������\n",
            environment( me ),({ me }) );
        write( "���ڵ������˰��죬ʲôҲû�з������㬵�վ��������\n" );
    }
    else
    {
        switch ( random( 4 ) )
        {
            case 1:
                message_vision( GRN"ͻȻ���ϳ���һֻͺ�գ��ڿ��������˰��죬��"
"$N����������\n"NOR,me );
                bird = new( __DIR__"npc/tujiu" );
                bird -> move( environment( me ) );
                bird -> kill_ob( me );
                remove_call_out( "tujiu_leave" );
                call_out( "tujiu_leave",5,me,bird );
                break;
            default:
                message( "vision",me->name() + "�ڵ������˰��죬��ҡҡͷվ��"
"������\n",environment( me ),({ me }) );
                write( "���ڵ������˰��죬ʲôҲû�з������㬵�վ��������\n" );
                break;
        }
    }
}

void tujiu_leave( object me,object ob )
{
    int ob_kee,ob_sen,ob_max_kee,ob_max_sen;
    object ob1;

    ob_kee = ob->query( "kee" );
    ob_sen = ob->query( "sen" );
    ob_max_kee = ob->query( "max_qi" );
    ob_max_sen = ob->query( "max_sen");
   
    if( (ob_kee/ob_max_kee)*100 > 50 || (ob_sen/ob_max_sen)*100 > 50 )
    {
        message_vision( YEL"$NͻȻվ������ͺ�շ���������ͺ���ܵ����ţ������Զ��"
"��ȥ��\n"NOR,me );
        destruct( ob );
    }
    else
    {
        message_vision( GRN"ͺ����$N�Ĺ����£����˲��ᣬ�����ŵ���������\n"NOR,me );
        destruct( ob );
        ob1 = new( __DIR__"npc/tujiu1" );
        ob1 ->move( this_object() );
    }
}
