/* nanmen.c
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
��������������ˡ����˳���һƬһ���޼ʵĲ�ԭ��
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "north"  : __DIR__"nanjie",
        "southwest" : "/d/xiyu/caoyuan1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


