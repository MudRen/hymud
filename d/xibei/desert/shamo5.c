/* shamo5.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980328
 * last modify add action lie
 */

#define DIR   __DIR__"shamo4"
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : __DIR__"shamo4",
         "right" : __DIR__"shamo" + ( random( 5 )+5 ),
         "backward":__DIR__"shamo6",
         "left" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "right" : __DIR__"shamo4",
         "backward" : __DIR__"shamo" + ( random( 5 )+5 ),
         "left":__DIR__"shamo6",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "backward" : __DIR__"shamo4",
         "left" : __DIR__"shamo"+( random( 5 )+5 ),
         "forward":__DIR__"shamo6",
         "right": __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
    ([ "left" : __DIR__"shamo4",
         "forward" : __DIR__"shamo" + ( random( 5 )+5 ),
         "right":__DIR__"shamo6",
         "backward" : __DIR__"shamo" + ( random( 5 )+5 ),
       ]),
});


void create()
{
    set( "short","大沙漠" );
    SetLong();
    set( "exits",exit[random( 4 )] );

    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 2 )
        new( __DIR__"obj/xiaostone" ) -> move( this_object() );
}

void init()
{
    add_action( "do_lie","lie" );
    add_action( "do_look",({ "look","l" }) );
    SetLong();
    remove_call_out("greet_me");    
    call_out("greet_me",1,this_player());
}

int do_lie( string arg )
{
    object me;
    me = this_player();

    if( arg ) return 0;
    if( me->is_fighting() )
        return notify_fail( RED"你正在战斗中，想找死啊。\n"NOR );
    if( me->is_busy() ) return notify_fail( "你现在正忙着呢。\n" );

    message( "vision",me->name() + "突然仰天倒下，躺在地上一动不动了。\n",
        environment( me ),({ me }) );
    write( "你仰天躺在地上，摒住呼吸，开始装死。\n" );
    me -> start_busy( 2 );               //busy 2 seconds
    remove_call_out( "tujiu_come" );     //after 10 seconds tujiu will come
    call_out( "tujiu_come",10,me );
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
        || (clock < 5 || clock > 20) || (clock > 10 && clock < 14) )
//在晚上或中午，或者生命体能>40%，秃鹫不会出现
    {
        message( "vision",me->name() + "在地上躺了半天，又摇摇头站了起来。\n",
            environment( me ),({ me }) );
        write( "你在地上躺了半天，什么也没有发生，悻悻地站了起来。\n" );
    }
    else
    {
// 不在上述条件下，有1/4的概率会出现秃鹫
        switch ( random( 4 ) )
        {
            case 1:
                message_vision( GRN"突然天上出现一只秃鹫，在空中盘旋了半天，向"
"$N俯冲下来。\n"NOR,me );
                bird = new( __DIR__"npc/tujiu" );
                bird -> move( environment( me ) );
                bird -> kill_ob( me );
                remove_call_out( "tujiu_leave" );
                call_out( "tujiu_leave",5,me,bird );
                break;
            default:
                message( "vision",me->name() + "在地上躺了半天，又摇摇头站了"
"起来。\n",environment( me ),({ me }) );
                write( "你在地上躺了半天，什么也没有发生，悻悻地站了起来。\n" );
                break;
        }
    }
}

//秃鹫出现后5 seconds,判断能否打下秃鹫。
void tujiu_leave( object me,object ob )
{
    int ob_kee,ob_sen,ob_max_kee,ob_max_sen;
    object ob1;

    ob_kee = ob->query( "kee" );
    ob_sen = ob->query( "sen" );
    ob_max_kee = ob->query( "max_qi" );
    ob_max_sen = ob->query( "max_sen");

//如果秃鹫的生命体能>50%,就会逃走。
    if( (ob_kee/ob_max_kee)*100 > 50 || (ob_sen/ob_max_sen)*100 > 50 )
    {
        message_vision( YEL"$N突然站起来向秃鹫发动攻击，秃鹫受到惊吓，震翅向远处"
"飞去。\n"NOR,me );
        destruct( ob );
    }
    else
    {
//否则得到一只受伤的秃鹫。
        message_vision( GRN"秃鹫在$N的攻击下，受伤不轻，扑腾着掉了下来。\n"NOR,me );
        destruct( ob );
        ob1 = new( __DIR__"npc/tujiu1" );
        ob1 ->move( this_object() );
    }
}
