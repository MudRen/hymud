/* houyuan.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","后院" );
    set( "long",@LONG
这里是波斯人铺子的后院，四周堆放着他从波斯运来的货物，还有一些从其
他商人那里收集来的商品。货物就这样乱七八糟的四散放着，一点也不整齐，在
西边的几棵树上，甚至还拴着几匹骆驼。南面就是波斯人开的铺子，从这里出了
东南角的小门，也可以直接走到大街上。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "southeast" : __DIR__"xijie2",
        "south"     : __DIR__"bosipu",
    ]) );
    set( "outdoors","xiyu" );
    setup();
}


