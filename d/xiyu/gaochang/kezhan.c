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
    set( "short","��ջ" );
    set( "long",@LONG
������λ�ڸ߲������ĵ�һ�ҿ�ջ���߲�����С���������ڴ˵����˺ܶ࣬
���Կ�ջ���������¡������ͬʱҲ��һ���Ƶ꣬�����м�ļ������ӱ�����
�ż�����˹���̣����������Ǹմ���ԭ������������ЪЪ�ţ���׼���������
������·�����ų�����һ������(sign)��
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
        "����"  :  "�ⷿÿ������������\n",
        "sign"  :  "�ⷿÿ������������\n",
    ]) );
    setup();
}

int valid_leave( object me,string dir )
{
    if( dir == "up" && !me->query_temp( "hydra/gaochang/ס��" ) )
    {
        if( present( "xiao er",environment( me ) ) )
            return notify_fail( "С����ס���㣬��������ס�����ȸ�Ǯ����\n" );
        else 
            return notify_fail( "����С�����ڣ��㻹�ǵ�һ������ס��ɡ�\n" );
    }
    
    return :: valid_leave( me,dir );
}

