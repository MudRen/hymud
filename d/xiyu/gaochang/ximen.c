/* ximen.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","高昌西门 " );
    set( "long",@LONG
终于来到了高昌的西门了，高昌城小，城墙也不算太高。门口来来往往都是
商贩，人声鼎沸，络绎不绝，有中原的，有波斯和印度的，还有那些高鼻子，蓝
眼珠的是罗马商人。出了城门往西，是一片很大的牧场。
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : "/d/xiyu/muchang2",
        "east" : __DIR__"xijie1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


