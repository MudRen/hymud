/* loulan3.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980408
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
������һЩ�д�ķ��ݣ�û���ݶ�����������ǽ�����ڡ�����֦��ɵ��飬
��Ĩ�ϻ��࣬���ɼ�ǽ����������Ť�ˣ���б����������ľ�Ĵ�����Ȼ�����ţ�
�ƺ����˸��߳����ţ�һ����ͻ������
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "north" : __DIR__"loulan2",
    ]) );

    set( "not_startroom",1 );
    setup();
}


