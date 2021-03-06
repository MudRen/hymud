/* lvzhou2.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","绿洲" );
    set( "long",@LONG
一个不小的湖泊，水面平静如镜、清澈见底，甚至在湖边也全无水沫，全无
涟漪的波动。湖畔全是草土，由于湖水的滋润，益发显得鲜艳，湖水里映出了鲜
丽无比的翠玉般的颜色。这里是沙漠边缘一块不小的绿洲，由于地势较低，天山
的雪水融化沿着小溪一直流到这里。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"yanqi",
        "east" : __DIR__"lvzhou1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


