/* dongjie.c
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
���˶��ž��Ƕ�����ˣ�������Ȼû����������֣����������и���ԭ����
�����￪�˸����ӣ�������������Ҳ�ܶࡣ·�����ź������������ţ�����
Ҳ��ɨ�øɸɾ����������ǳ��ţ���������Ǽ���ԭ���ӡ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"center",
        "east"  : __DIR__"dongmen",
        "south" : __DIR__"zhongguopu",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


