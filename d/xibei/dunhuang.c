/* dunhuang.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","�ػ�" );
    set( "long",@LONG
�ػ��Ǻ����������˵��Ż��������Źؽ����Ժ�ĵ�һ������������ɽѩ
�룬����λ����Ҫ��˿��֮·�������жν����ڴˣ���˿��֮·������Ŧ������
���Ǳ���Ϊ��ǧ�����ҡ���Ī�߿ߣ������������Źء����ؾ���һ���޼ʵĴ�ɳ
Į�ˡ�
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "northwest" : __DIR__"yumenguan",
        "east" : __DIR__"silk11",
        "southeast" : __DIR__"mogaoku",
    ]) );
    set( "outdoors","silk");
    setup();
}


