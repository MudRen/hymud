/* dunhuang.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","敦煌" );
    set( "long",@LONG
敦煌是河西走廊西端的门户，是玉门关进来以后的第一重镇。南枕祁连山雪
岭，地理位置险要，丝绸之路东段与中段交汇于此，是丝绸之路的总枢纽。东南
方是被称为“千佛灵岩”的莫高窟，往西过了玉门关、阳关就是一望无际的大沙
漠了。
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "northwest" : __DIR__"yumenguan",
        "east" : __DIR__"silk11",
        "southeast" : __DIR__"mogaoku",
    ]) );
    set( "outdoors","silk");
    setup();
}


