/* loulan1.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980327
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","�ų�ǽ" );
    set( "long",@LONG
������һ���ƾɵĳ�ǽ����ǽ�û����ݳɡ���Ϊ����������İ�ʴ���󲿷�
���ѻ�Ϊ���У�ֻ�����ﻹ���߲�����һС�Σ���Լ����ͨ������ô�ߡ�����
��һ���ܸߵ����ѣ�������������֦��έ�����ɣ���ϡ���Կ�����һ�����˵ķ�
���������вд������ͱڻ���
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "east" : __DIR__"loulan2",
        "west" : __DIR__"shamo"+random( 5 ),
    ]) );
    set( "not_startroom",1 );
    setup();
}


