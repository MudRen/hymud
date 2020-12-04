/* caoyuan1.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","��ԭ" );
    set( "long",@LONG
һ���޼ʵĴ��ԭ�������͵���ݸպ�û�ţ�����ȥ�ǳ��������Զ��ţ��
��Ⱥ���ڳ��Ųݣ������Ʈ�ż�����ƣ�һ����ȥ����ֲ���������Ⱥ�����ǰ�
�ơ�һֻ��Ӳݴ��з���Ʈ�ݶ��˵ظ����ڿ�������ɫ�Ĳ����һ�������
�ߴ���ʧӰ�٣�ֻ����һ��С�ڵ���������
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "north" : __DIR__"caoyuan2",
        "northeast" : __FILE__,
        "southwest" : __FILE__,
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "northeast" && me->query_temp( "steps/caoyuan1" ) >= 5)
    {
        me -> delete_temp( "steps/caoyuan1" );
        me -> move( __DIR__"gaochang/nanmen" );
        return notify_fail( "\n" );
    }

    if( dir == "southwest" && me->query_temp( "steps/caoyuan1" ) <= -5 )
    {
        me -> delete_temp( "steps/caoyuan1" );
        me -> move( __DIR__"yanqi" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "northeast":
            me -> add_temp( "steps/caoyuan1",1 );
            break;
        case "southwest":
            me -> add_temp( "steps/caoyuan1",-1 );
            break;
    }
    return ::valid_leave( me,dir );
}

