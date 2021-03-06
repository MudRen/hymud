/* guizi.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","龟兹" );
    set( "long",@LONG
龟兹位于丝绸之路的天山南麓分支上，地处要冲，是西域文化和中原文化交
流融合的地方。由于其特殊的地理位置，这里成了西域各国争夺的中心。龟兹还
以其音乐闻名，自隋以后，龟兹音乐传入中原，成为中原官家舞曲的主要曲目，
并跟中原音乐互相融合，发展。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northeast" : __DIR__"caoyuan2",
        "south" : __DIR__"nanjiang0",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


