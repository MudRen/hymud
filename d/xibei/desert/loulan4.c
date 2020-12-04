/* loulan4.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980408
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","古墓地" );
    set( "long",@LONG
七排木桩包围着这里，围成一个椭圆形的地方。从隆起的土包和地下洒落着
的白骨可以看出这里应该是一个墓地。由于大漠的吞噬，城堡的覆灭，这里一片
荒凉，偶尔大风刮过，发出翁翁的响声。
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "west" : __DIR__"loulan2",
    ]) );

    set( "not_startroom",1 );
    setup();
}


