/* xijie2.c
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
����ˣ�ģ����̵ģ�˵���ġ��������У����嶣������˻������������һ�ҿ�
ջ������㳤;�������ˣ����Ե�����ȥЪϢһ�¡�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"xijie1",
        "east"  : __DIR__"center",
        "north" : __DIR__"kezhan",
        "south" : __DIR__"dangpu",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


