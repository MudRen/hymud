/* kezhan.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","客栈" );
    set( "long",@LONG
这里是位于高昌城中心的一家客栈。高昌称虽小，但来往于此的商人很多，
所以客栈的生意很兴隆。这里同时也是一个酒店，在屋中间的几张桌子边坐着
着几个波斯客商，看样子他们刚从中原过来，到这里歇歇脚，以准备后面更加
漫长的路。进门出立着一块牌子(sign)。
LONG
    );

    set( "exits",([ /* sizeof() == 1 */
        "south" : __DIR__"xijie2",
        "up"    : __DIR__"kefang",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/waiter":1,
    ]) );
    set( "detail",([
        "牌子"  :  "租房每次纹银三两。\n",
        "sign"  :  "租房每次纹银三两。\n",
    ]) );
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "up" && !me->query_temp( "hydra/gaochang/住店" ) )
    {
        if( present( "xiao er",environment( me ) ) )
            return notify_fail( "小二拦住了你，道：“想住店请先付钱。”\n" );
        else 
            return notify_fail( "现在小二不在，你还是等一下在来住店吧。\n" );
    }
    
    return :: valid_leave( me,dir );
}

