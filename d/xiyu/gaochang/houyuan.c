/* houyuan.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","��Ժ" );
    set( "long",@LONG
�����ǲ�˹�����ӵĺ�Ժ�����ܶѷ������Ӳ�˹�����Ļ������һЩ����
�����������ռ�������Ʒ��������������߰������ɢ���ţ�һ��Ҳ�����룬��
���ߵļ������ϣ�������˩�ż�ƥ���ա�������ǲ�˹�˿������ӣ����������
���Ͻǵ�С�ţ�Ҳ����ֱ���ߵ�����ϡ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "southeast" : __DIR__"xijie2",
        "south"     : __DIR__"bosipu",
    ]) );
    set( "outdoors","xiyu" );
    setup();
}


