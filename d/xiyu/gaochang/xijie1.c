/* xijie1.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","����� " );
    set( "long",@LONG
�����Ǹ߲�������ĵط��ˣ��������Ҫ�̼ҵ궼�����������֮�⣬
��ֵ�����Ҳ�����˸���̯�ӡ����ڽ��ϣ����ָ������˶��У�����ʳС�Եģ�
����ˣ�ģ����̵ģ�˵���ġ��������У����嶣������˻������������һ�Ҳ�
˹�˿������ӣ�����������һ��ӡ���˿��ġ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"ximen",
        "east"  : __DIR__"xijie2",
        "north" : __DIR__"bosipu",
        "south" : __DIR__"yindupu",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


