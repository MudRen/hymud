/* loulan4.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980408
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980408
 */

inherit ROOM;

void create()
{
    set( "short","��Ĺ��" );
    set( "long",@LONG
����ľ׮��Χ�����Χ��һ����Բ�εĵط�����¡��������͵���������
�İ׹ǿ��Կ�������Ӧ����һ��Ĺ�ء����ڴ�Į�����ɣ��Ǳ��ĸ�������һƬ
������ż�����ι����������̵�������
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "west" : __DIR__"loulan2",
    ]) );

    set( "not_startroom",1 );
    setup();
}


