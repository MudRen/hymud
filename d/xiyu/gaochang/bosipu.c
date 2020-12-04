inherit ROOM;

void create()
{
    set( "short","波斯铺" );
    set( "long",@LONG
这里是波斯商人在这里开的铺子，他在这里出售他从波斯运来的特产，然后
收集东方的货物运到波斯去卖。在靠东边的墙上，挂满了各种物品，香料、玻璃
是他从波斯带过来的，丝绸、陶瓷是他买了准备下次回去的时候再带回去的。他
有一个驼队，每次都可以运很多货。
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "south" : __DIR__"xijie1",
        "north" : __DIR__"houyuan",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/shangren2":1,
    ]) );
    setup();
}


