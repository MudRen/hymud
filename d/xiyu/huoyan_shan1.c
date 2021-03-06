/* huoyan_shan1.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","火焰山" );
    set( "long",@LONG
火焰山，全是裸露着的红色砂宕，没有任何土壤草木覆被。在干旱、酷热而
又多风沙的吐鲁番盆地，站在灼人的阳光，迎着扑面的热风热浪，看风尘迷茫的
红色山岩，真象一堆堆燃着烈焰的炭火，山顶的风尘，恰象火堆上飞腾的烟云。
地上沙石灼人皮肉，向有“火洲”之称。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"huoyan_shan",
        "east" : __DIR__"huoyan_shan2",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


