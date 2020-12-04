/* nanmen.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","高昌南门 " );
    set( "long",@LONG
终于来到了高昌的南门了，高昌城小，城墙也不算太高。门口来来往往都是
商贩，人声鼎沸，络绎不绝，有中原的，有波斯和印度的，还有那些高鼻子，蓝
眼珠的是罗马商人。出了城门一片一望无际的草原。
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "north"  : __DIR__"nanjie",
        "southwest" : "/d/xiyu/caoyuan1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


