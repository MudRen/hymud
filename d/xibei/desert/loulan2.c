/* loulan2.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980408
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

#include <ansi.h>
#include <localtime.h>

inherit ROOM;

void create()
{
    set( "short","���ƹ���" );
    set( "long",@LONG
�����ο��Բ³���������ǰ�϶���һ�������Ĺ���������ɵķ��ӣ��ֺ�
�Ĵ�ľ���ߴ��������������������Ա��ϳ�������Щ����ľ��ľ���ϣ��е���
���ۣ��������ϻ��ƣ���������עĿ�����������Ŷ��˵�ľ�������ӣ��ȱȽ��ǣ�
��Ŀ�Ǽ����ڹ���ǰ����ϡ���Կ���ԭ����һ�ھ�������ѹ��һ���ʯ��
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "west" : __DIR__"loulan1",
        "southeast" : "/d/loulan/kongquehe",
        "south" : __DIR__"loulan3",
        "east" : __DIR__ "loulan4",
    ]) );
    set( "detail",([
        "��ʯ":"����ʯ��ѹס�˾��ڣ�����������ܷ������(push)����\n",
    ]) );
    set( "stone_on_well",1 );
    set( "is_center",1 );
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "PushStone","push" );
}

int PushStone( string arg )
{
    object me,snake1,snake2;
    int my_force,my_max_force,lhour;
    mixed * ltime;

    me = this_player();
    my_force = me->query( "neili" );
    my_max_force = me->query( "max_neili" );
    //ltime = NATURE_D->game_time(1);
    //lhour = ltime[LT_HOUR];

    if( arg != "stone" && arg != "��ʯ" ) return 0;
    if( me->is_busy() )
        return notify_fail( "����æ���ء�\n" );
    if( me->is_fighting() )
        return notify_fail( "������ս���С�\n" );
    if( !this_object()->query( "stone_on_well" ) )
        return notify_fail( "ʯͷ�Ѿ����ڵ����ˣ�����ʲô?\n" );
    if( random(2)==0 )
        return notify_fail( "������ȥ����һ���ǿ��ʯ�����Ǿ�ʯ��˿������\n" );
    if( random(2)==0 )
        return notify_fail( "������ȥ����һ���ǿ��ʯ������ʯͷֻ�ǻ���һ�Ρ�\n");
    message_vision( "$N�ߵ����ߣ�������ӣ����������������ǿ��ʯ��ȥ��"
        "����\n",me );
/*    if( lhour > 4 && lhour < 21 )
    {
        message_vision( "���Ǿ�ʯһ��������������\n",me );
        me -> add( "force",-200 );
        return 1;
    }*/
    message_vision( "ֻ����ʯ����������������¶����һ˿��϶������\n"
        "ͻȻ����\n\n",me );
    this_object()->set( "stone_on_well",0 );
    this_object()->set( "detail/��ʯ","һ��޴��ʯͷ������֪����˭�Ƶ��˵��ϡ�\n");
    message_vision( HIY"���дܳ�"NOR+RED"��"NOR+BLU"��"+HIY"���⣬������������Ӿ���"
        "��Ծ��������\n"NOR,me );
    message_vision( HIY"����Ѹ���ޱȵ���$N��ȥ������\n"NOR,me );
    me -> add( "neili",-200 );
    snake1 = new( __DIR__"npc/blue_snake" );
    snake2 = new( __DIR__"npc/red_snake" );
    snake1 -> move( this_object() );
    snake1 -> kill_ob( me );
    snake2 -> move( this_object() );
    snake2 -> kill_ob( me );
    call_out( "PplDie",60,me );
    return 1;
}

void create_exit()
{
    set( "exits/down",__DIR__"underwell" );
    call_out( "close_exit",5 );
}

void close_exit()
{
    delete( "exits/down" );
}            

void PplDie( object me )
{
    object snake1,snake2;
    
    if( !snake1 = present( "red boa",environment( me ) ) )
    {
        return;
    }
    if( !snake2 = present( "blue boa",environment( me ) ) )
    {
        return;
    }
    if( ( objectp( snake1 ) && !living( snake1 ) ) ||
        ( objectp( snake2 ) && !living( snake2 ) ) )
    {
        return;
    }

    message_vision( YEL"ֻ������Ծ����գ�����һ�����У�Ȼ��ͻȻ�³�һ�����ߣ�"
        "��\n��$N�ز���Ȼ��һ��ͷ�������Ϸ���ȥ����\n"NOR,me );
    me -> die();
    if( snake1 )
    { 
        destruct( snake1 );
    }
    if( snake2 )
    {
        destruct( snake2 );
    }
create_exit();
}

        
