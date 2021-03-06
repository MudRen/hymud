/* caoyuan2.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","草原" );
    set( "long",@LONG
坦平的草原，一望无际，整个地面形成了金色带绿的海洋，上面点缀着千万
朵各种各样的花。细厂的草茎中间露出淡青色的、蓝色的和淡紫色的叫不出名的
野花。空中充满着千百种各种各样的鸟鸣。兀鹰静止不动地停在天空，展开双翼
把眼睛呆呆地注视着草原。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "south" : __DIR__"caoyuan1",
        "northeast" : __FILE__,
        "southwest" : __FILE__,
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "northeast" && me->query_temp( "steps/caoyuan2" ) >= 2)
    {
        me -> delete_temp( "steps/caoyuan2" );
        me -> move( __DIR__"yanqi" );
        return notify_fail( "\n" );
    }

    if( dir == "southwest" && me->query_temp( "steps/caoyuan2" ) <= -2 )
    {
        me -> delete_temp( "steps/caoyuan2" );
        me -> move( __DIR__"guizi" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "northeast":
            me -> add_temp( "steps/caoyuan2",1 );
            break;
        case "southwest":
            me -> add_temp( "steps/caoyuan2",-1 );
            break;
    }
    return ::valid_leave( me,dir );
}
