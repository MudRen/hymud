/* minzhai.c ��լ
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","��լ" );
    set( "long",@LONG
һ����ͨ����լ����Ȼ�ش����򣬵������������ȴ�Ǹ���ԭ�ˡ���˵��֪
ʶԨ���������ڿƾٵ�ʱ��ȴδ���а�һ��֮�£���һ֧�̶Ӵ�����Į����
�����Ȼ�����򵱵����˽�����ԭ��Ϊ�����������Լ���д��һЩ�伮������
���ӹ��Ļ��Ǻܽ���
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "east"   : __DIR__"nanjie",
    ]) );
    set( "objects",([
        __DIR__"npc/teacher":1,
    ]) );
    setup();
}


