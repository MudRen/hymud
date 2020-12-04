/* dongjie.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","东大街 " );
    set( "long",@LONG
进了东门就是东大街了，这里虽然没有西大街热闹，但是由于有个中原商人
在这里开了个铺子，所以往来的人也很多。路边两排胡杨，整齐地排列着，街上
也打扫得干干净净。东面是城门，南面就是那家中原铺子。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"center",
        "east"  : __DIR__"dongmen",
        "south" : __DIR__"zhongguopu",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


