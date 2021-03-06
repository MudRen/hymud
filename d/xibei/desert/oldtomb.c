/* oldtomb.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 */

inherit ROOM;

void create()
{
    set( "short","古墓" );
    set( "long",@LONG
这里是一座古墓。墓的中央南北向放着一具铜棺，周围排列着八具陪葬的木
棺。铜棺盖上伸出十二个铜钮，底下有十个兽蹄形的圆铜足；陪葬棺外面均有彩
漆。铜棺的下面放的是一些陪葬品。在墓靠东壁出，有一个架子，上面放着一本
残破的书。
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "up" : __DIR__"loulan4",
    ]) );
    set( "search_things",([
        "架子":__DIR__"obj/shamo_map",
    ]) );
    set( "not_startroom",1 );
    setup();
}


