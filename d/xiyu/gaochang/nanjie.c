/* nanjie.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","�ϴ�� " );
    set( "long",@LONG
�ϴ��Զû����������֣��������Ծ�ס�ŵĶ��ǱȽ�ƶ��İ��գ�����û
��Ǯ��ʲô�ݳ޵Ķ��������������Ƕ���������������̯������ż���߹���Ҳ��
һЩ��·�Ŀ��̡������������Ǹ߲������ţ����������еıؾ�֮·��
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "north"  : __DIR__"center",
        "south"  : __DIR__"nanmen",
        "west"   : __DIR__"minzhai",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


