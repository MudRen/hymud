/* muchang2.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","山脚牧场" );
    set( "long",@LONG
就在雪峰的围绕中，一片绮丽的千里牧场展现在你的眼前。白皑皑的雪山和
鲜艳的野花，给这辽阔的千里牧场镶上了双重富丽的花边。千里牧场上长着一色
青翠的酥油草，清清的溪水齐着两岸的草丛在漫流。草原是这样的无边的平展，
就象风平浪静的海洋。在太阳下，那点点水泡似的帐篷在闪烁着白光。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
       "east"  : __DIR__"gaochang/ximen",
        "west" : __DIR__"muchang1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


