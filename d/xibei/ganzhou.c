/* ganzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","甘州" );
    set( "long",@LONG
甘州是丝绸之路上的一大咽喉重镇。北部龙首山、北大山、合黎山、夹山构
成了这个地区北部的天然屏障，弱水流经此地，穿过合黎山与夹山之间的戈壁，
向北方的居延海流去，形成一道险要关隘。与龙首山遥遥相对的，便是终年积雪
的祁连山，皑皑莽莽，绵延千里，那时南阻青海的天然屏障。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"silk7",
        "southeast" : __DIR__"silk6",
    ]) );
    set( "outdoors","silk");
    setup();
}


