/* oldtomb.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 */

inherit ROOM;

void create()
{
    set( "short","��Ĺ" );
    set( "long",@LONG
������һ����Ĺ��Ĺ�������ϱ������һ��ͭ�ף���Χ�����Ű˾������ľ
�ס�ͭ�׸������ʮ����ͭť��������ʮ�������ε�Բͭ�㣻�����������в�
�ᡣͭ�׵�����ŵ���һЩ����Ʒ����Ĺ�����ڳ�����һ�����ӣ��������һ��
���Ƶ��顣
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "up" : __DIR__"loulan4",
    ]) );
    set( "search_things",([
        "����":__DIR__"obj/shamo_map",
    ]) );
    set( "not_startroom",1 );
    setup();
}


