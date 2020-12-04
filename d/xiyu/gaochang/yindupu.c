/* yindupu.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","印度铺" );
    set( "long",@LONG
这里是印度商人开的铺子，铺子的主人正忙碌着招呼顾客。这个店铺虽然不
大，装饰简朴，但是印度人非常热情，再加上他的货物美价廉，所以这里的顾客
很多。你也不时可以看到一些从中原来的商人到这里成匹的购买货物，然后到中
原去卖。
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "north" : __DIR__"xijie1",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/shangren1":1,
    ]) );
    setup();
}


