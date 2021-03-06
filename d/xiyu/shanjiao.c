/* shanjiao.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","天山脚下" );
    set( "long",@LONG
连绵不绝的天山就在你的眼前。远望天山，美丽多姿，那长年积雪高插云霄
的云峰，象少女头上的珠冠，银光闪闪；那富于色彩的不断的山峦，象孔雀正在
开屏，艳丽迷人。天山有丰饶的水草，有绿发似的森林，有终年不化的积雪，当
然还有各种珍贵的药材。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "east" : __DIR__"muchang",
    "southwest" : "/d/xingxiu/shanjiao",	
    ]) );
    set( "outdoors","xiyu");
    setup();
}


