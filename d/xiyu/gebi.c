/* gebi.c  戈壁
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980428
 */

inherit ROOM;

void create()
{
    set( "short","戈壁" );
    set( "long",@LONG
你放眼望去，但见无边的戈壁，没有任何草木的踪影，一种茫茫然的心情油
然而生。眼前满盖着的是一层石砾积成的硬壳，而远处依稀是山影重重。暴风烈
日和无情的岁月，曾经把多少高山深谷都夷为平地，劈裂成破碎焦黑的砾石，这
些砾石在烈日的斜照下反射出一片银色的光辉，给人一种一望无际，严峻，空漠，
酷烈的感觉。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __FILE__,
        "east" : __FILE__,
    ]) );
    set( "quyu","xiyu" );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    int water;
    water = me -> query( "water" );
    water -= 5;
    if( dir == "west" && me->query_temp( "steps/gebi" ) >= 7)
    {
        me -> delete_temp( "steps/gebi" );
        me -> move( __DIR__"huoyan_shan2" );
        return notify_fail( "\n" );
    }

    if( dir == "east" && me->query_temp( "steps/gebi" ) <= -7 )
    {
        me -> delete_temp( "steps/gebi" );
        me -> move( __DIR__"hami/xiaolu01" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "west":
            me -> add_temp( "steps/gebi",1 );
            break;
        case "east":
            me -> add_temp( "steps/gebi",-1 );
            break;
    }
    if( water > 0 )
    {
        me -> set( "water",water );
    }
    else
        me -> set( "water",0 );
    return ::valid_leave( me,dir );
}

