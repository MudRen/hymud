/* kefang.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","��¥�ͷ�" );
    set( "long",@LONG
��Ȼ�ͷ��Ƚ�С��ǽ����Ҳû��ʲôװ�εĶ�������������Ŀͷ���ɨ�ĸ�
�ɾ��������ϱ���Ҳ�������룬������һ�����ĵĸо�����о�����Щ���ˣ���
�ø�������˯һ���ˡ���Ȼ�ϱߵĴ���Ϸǳ����֣���������ȴ�ܰ�����
LONG
    );
    set( "sleep_room","inn" );
    set( "exits",([ /* sizeof() == 1 */
        "down" : __DIR__"kezhan",
    ]) );
    setup();
}

