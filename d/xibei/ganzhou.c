/* ganzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
������˿��֮·�ϵ�һ���ʺ����򡣱�������ɽ������ɽ������ɽ����ɽ��
�������������������Ȼ���ϣ���ˮ�����˵أ���������ɽ���ɽ֮��ĸ�ڣ�
�򱱷��ľ��Ӻ���ȥ���γ�һ����Ҫ�ذ���������ɽңң��Եģ����������ѩ
������ɽ������çç������ǧ���ʱ�����ຣ����Ȼ���ϡ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"silk7",
        "southeast" : __DIR__"silk6",
    ]) );
    set( "outdoors","silk");
    setup();
}


