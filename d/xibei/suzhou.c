/* suzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
���ݣ��ֳƾ�Ȫ���ش���������������������ɽ����֮�£��Ǽ�����������
��һ������Ҳ��˿��֮·�����Źغ�ĵڶ�����ҵ��ó�׵㣬Ҳ����ެ���ɹ�
����������Ľ�ͨҪ�ڣ�Ϊ�������ұ���֮�ء��ݴ������Ǵ󽫻�ȥ���Ѻ����
Ϊ��������ս���ʹ͸��������Ƶ���Ȫ���뽫ʿ����͵�������Ȫ����
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"silk9",
        "east" : __DIR__"silk8",
    ]) );
    set( "outdoors","silk");
    setup();
}


