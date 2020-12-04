/* caoyuan2.c
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
̹ƽ�Ĳ�ԭ��һ���޼ʣ����������γ��˽�ɫ���̵ĺ��������׺��ǧ��
����ָ����Ļ���ϸ���Ĳݾ��м�¶������ɫ�ġ���ɫ�ĺ͵���ɫ�Ľв�������
Ұ�������г�����ǧ���ָ��ָ�����������أӥ��ֹ������ͣ����գ�չ��˫��
���۾�������ע���Ų�ԭ��
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "south" : __DIR__"caoyuan1",
        "northeast" : __FILE__,
        "southwest" : __FILE__,
    ]) );
    set( "outdoors","xiyu");
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "northeast" && me->query_temp( "steps/caoyuan2" ) >= 2)
    {
        me -> delete_temp( "steps/caoyuan2" );
        me -> move( __DIR__"yanqi" );
        return notify_fail( "\n" );
    }

    if( dir == "southwest" && me->query_temp( "steps/caoyuan2" ) <= -2 )
    {
        me -> delete_temp( "steps/caoyuan2" );
        me -> move( __DIR__"guizi" );
        return notify_fail( "\n" );
    }
    switch( dir )
    {
        case "northeast":
            me -> add_temp( "steps/caoyuan2",1 );
            break;
        case "southwest":
            me -> add_temp( "steps/caoyuan2",-1 );
            break;
    }
    return ::valid_leave( me,dir );
}
