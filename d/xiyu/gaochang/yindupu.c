/* yindupu.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","ӡ����" );
    set( "long",@LONG
������ӡ�����˿������ӣ����ӵ�������æµ���к��˿͡����������Ȼ��
��װ�μ��ӣ�����ӡ���˷ǳ����飬�ټ������Ļ�������������������Ĺ˿�
�ܶࡣ��Ҳ��ʱ���Կ���һЩ����ԭ�������˵������ƥ�Ĺ�����Ȼ����
ԭȥ����
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "north" : __DIR__"xijie1",
    ]) );
    set( "objects",([ /* sizeof() == 1 */
        __DIR__"npc/shangren1":1,
    ]) );
    setup();
}


