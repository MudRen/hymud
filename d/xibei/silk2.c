/* silk2.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","��������" );
    set( "long",@LONG
���������ǻƺ�����һ����Ҫ�Ľ�ͨҪ��������ԭͨ������ıؾ�֮�أ�Ҳ
�Ǳ���������ص㡣һ�����������������Ĵ��������ǰչ�����տ��������
ãã�ġ���������ͻ�ԭ��ͨ���裬����һ��Ƭ�谵�ĵ���ƽ�������룬������
ͷ�ڷ��м��һ���죬һֱ�쵽��Զ����߲���ʧ��
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"silk3",
        "southeast" : __DIR__"silk1",
    ]) );
    set( "outdoors","silk");
    setup();
}


