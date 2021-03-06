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
    set( "short","残破宫殿" );
    set( "long",@LONG
从外形可以猜出，这里以前肯定是一座豪华的宫殿，土坯砌成的房子，粗厚
的椽木、高大的门柱、朱漆的梁还可以辨认出来。这些胡杨木的木材上，有的凿
了眼，甚至刻上花纹，格外引人注目。地下洒落着断了的木梁，椽子，比比皆是，
满目狼籍。在宫殿前面依稀可以看出原来是一口井，井上压着一块巨石。
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
        "巨石":"这快巨石正压住了井口，你可以试试能否把他搬(push)开。\n",
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

    if( arg != "stone" && arg != "巨石" ) return 0;
    if( me->is_busy() )
        return notify_fail( "你正忙着呢。\n" );
    if( me->is_fighting() )
        return notify_fail( "你正在战斗中。\n" );
    if( !this_object()->query( "stone_on_well" ) )
        return notify_fail( "石头已经落在地上了，还推什么?\n" );
    if( random(2)==0 )
        return notify_fail( "你走上去推了一把那块巨石，但是巨石纹丝不动。\n" );
    if( random(2)==0 )
        return notify_fail( "你走上去推了一下那块巨石，但是石头只是晃了一晃。\n");
    message_vision( "$N走到井边，半蹲身子，发力向盖在上面的那块巨石推去。"
        "。。\n",me );
/*    if( lhour > 4 && lhour < 21 )
    {
        message_vision( "但是巨石一动都不动。。。\n",me );
        me -> add( "force",-200 );
        return 1;
    }*/
    message_vision( "只见巨石慢慢地上升，井口露出了一丝缝隙。。。\n"
        "突然。。\n\n",me );
    this_object()->set( "stone_on_well",0 );
    this_object()->set( "detail/巨石","一块巨大的石头，但不知道被谁推到了地上。\n");
    message_vision( HIY"井中窜出"NOR+RED"红"NOR+BLU"蓝"+HIY"二光，随后两条巨蟒从井中"
        "飞跃而出。。\n"NOR,me );
    message_vision( HIY"它们迅疾无比地向$N扑去。。。\n"NOR,me );
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

    message_vision( YEL"只见巨蟒跃至半空，发出一声鸣叫，然后突然吐出一道光线，"
        "正\n中$N胸部。然后一仰头，向天上飞了去。。\n"NOR,me );
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

        
