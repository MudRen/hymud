/* dongmen.c
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
���������˸߲��Ķ����ˣ��߲���С����ǽҲ����̫�ߡ��ſ�������������
�̷����������У����ﲻ��������ԭ�ģ��в�˹��ӡ�ȵģ�������Щ�߱��ӣ���
��������������ˡ����˳�����������һƬ���ȵĻ���ɽ��Ȼ���������ߣ��Ϳ�
�Ե�������ˡ�
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "west"  : __DIR__"dongjie",
        "east" : "/d/xiyu/huoyan_shan",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


