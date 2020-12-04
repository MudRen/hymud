/* gebi.c  ���
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980428
 */

inherit ROOM;

void create()
{
    set( "short","���" );
    set( "long",@LONG
�������ȥ�������ޱߵĸ�ڣ�û���κβ�ľ����Ӱ��һ��ããȻ��������
Ȼ��������ǰ�����ŵ���һ��ʯ�����ɵ�Ӳ�ǣ���Զ����ϡ��ɽӰ���ء�������
�պ���������£������Ѷ��ٸ�ɽ��ȶ���Ϊƽ�أ����ѳ����齹�ڵ���ʯ����
Щ��ʯ�����յ�б���·����һƬ��ɫ�Ĺ�ԣ�����һ��һ���޼ʣ��Ͼ�����Į��
���ҵĸо���
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __FILE__,
        "east" : __FILE__,
    ]) );
    set( "quyu","xiyu" );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    int water;
    water = me -> query( "water" );
    water -= 5;
    if( dir == "west" && me->query_temp( "steps/gebi" ) >= 7)
    {
        me -> delete_temp( "steps/gebi" );
        me -> move( __DIR__"huoyan_shan2" );
        return notify_fail( "\n" );
    }

    if( dir == "east" && me->query_temp( "steps/gebi" ) <= -7 )
    {
        me -> delete_temp( "steps/gebi" );
        me -> move( __DIR__"hami/xiaolu01" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "west":
            me -> add_temp( "steps/gebi",1 );
            break;
        case "east":
            me -> add_temp( "steps/gebi",-1 );
            break;
    }
    if( water > 0 )
    {
        me -> set( "water",water );
    }
    else
        me -> set( "water",0 );
    return ::valid_leave( me,dir );
}

