/* silk10.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980426
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980426
 */

inherit ROOM;

void create()
{
    set( "short","˿��֮·" );
    set( "long",@LONG
����һ��������ԭ����������ŷ�޵Ľ�ͨҪ����������ŷ��½֮����̶�
���Ǵ����ﾭ�������ǰ��й�������˿���Լ�ֽ�Ŵ�����ŷ�ޣ�ͬʱ��ȥ�Ļ���
�й���������ꣻ�����������Ĵ���ʿ�Űѷ�̡���˹���̴������й���������
�ﲻ�ǿ��Կ������ػ�����նӾ�����
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"silk11",
        "southeast" : __DIR__"silk9",
    ]) );
    set( "outdoors","silk");
    setup();
}


