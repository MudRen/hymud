/* huoyan_shan.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","����ɽ" );
    set( "long",@LONG
����ɽ��ȫ����¶�ŵĺ�ɫɰ崣�û���κ�������ľ�������ڸɺ������ȶ�
�ֶ��ɳ����³����أ�վ�����˵����⣬ӭ��������ȷ����ˣ����糾��ã��
��ɫɽ�ң�����һ�Ѷ�ȼ�������̿��ɽ���ķ糾��ǡ�����Ϸ��ڵ����ơ�
����ɳʯ����Ƥ�⣬���С����ޡ�֮�ơ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"gaochang/dongmen",
        "east" : __DIR__"huoyan_shan1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


