/* guizi.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
����λ��˿��֮·����ɽ��´��֧�ϣ��ش�Ҫ�壬�������Ļ�����ԭ�Ļ���
���ںϵĵط�������������ĵ���λ�ã�����������������������ġ����Ȼ�
�������������������Ժ󣬹������ִ�����ԭ����Ϊ��ԭ�ټ���������Ҫ��Ŀ��
������ԭ���ֻ����ںϣ���չ��
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northeast" : __DIR__"caoyuan2",
        "south" : __DIR__"nanjiang0",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


