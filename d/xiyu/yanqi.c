/* yanqi.c
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
���������򱱵���Ҫ�壬��ͨ��ɽɽ���Ĵ��ԣ�պӣ���������Ų�˹�ں�
����������ԭ������������Ҹ��Ӷ���Ҫ�ĳ�ͻ�У����ŷǳ���Ҫ�����á��Ƴ�
���ڴ��������������������Ĵ�����֮һ�����������ɽ���������ء�����Ȫˮ
Ϫ����֯���������ḻ��
LONG
    );

    set( "exits",([ /* sizeof() ==3 */
        "northeast" : __DIR__"caoyuan1",
        "southeast" : __DIR__"lvzhou2",
        "southwest" : __DIR__"caoyuan2",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


