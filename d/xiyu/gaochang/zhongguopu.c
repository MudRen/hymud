/* zhongguopu.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","�ӻ���" );
    set( "long",@LONG
������һλ��ԭ�������˿������ӣ���Ҫ����ԭ���ز���ҩ������˿��ʲô
�ģ���֪����Ϊʲô�����Ⲣ��������Ķ�����Ͽ��������ӣ�������������
���Զ�������������Ҳѡ����������еĶ��ߡ�������������˿��ҩ�Ķ�����
��ӭ����������������Ȼλ�ò��ã���������ȴ��Ȼ�ȽϺ��
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "north" : __DIR__"dongjie",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/shangren3":1,
    ]) );
    setup();
}


