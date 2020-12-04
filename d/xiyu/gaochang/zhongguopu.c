/* zhongguopu.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","杂货铺" );
    set( "long",@LONG
这里是一位中原来的商人开的铺子，主要卖中原的特产，药材啦，丝绸什么
的，不知道他为什么挑在这并不是最繁华的东大街上开他的铺子，可能是由于他
来自东方，所以铺子也选在了这个城市的东边。由于他带来的丝绸、药材都很受
欢迎，所以他的铺子虽然位置不好，但是生意却仍然比较红火。
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "north" : __DIR__"dongjie",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/shangren3":1,
    ]) );
    setup();
}


