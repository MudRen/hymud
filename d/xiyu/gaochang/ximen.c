/* ximen.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","�߲����� " );
    set( "long",@LONG
���������˸߲��������ˣ��߲���С����ǽҲ����̫�ߡ��ſ�������������
�̷����������У����ﲻ��������ԭ�ģ��в�˹��ӡ�ȵģ�������Щ�߱��ӣ���
��������������ˡ����˳�����������һƬ�ܴ��������
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : "/d/xiyu/muchang2",
        "east" : __DIR__"xijie1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


