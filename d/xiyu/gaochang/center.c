/* center.c
 * from XO Lib
 * a room of gaochang
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","������" );
    set( "long",@LONG
�����Ǹ߲��ǵ����ģ��ڸ߲����ǵ����棬�ſ���������ֵĽ��㴦������
���Ǹ߲��Ĺ��ǣ�����ǰ�߲�������ס�ĵط����������Ѿ���������ռ���ˡ���
���ǵش�����ó�׵�Ҫ�壬���������˴��Ҫ�����ڴˣ��������﷢չ��������
һ����С�ĳ��С��������Ҳ�ܷḻ��ͻ������ԭ˿�񣬲�˹���գ�ӡ��ҩ�ģ�
���ֵ��̺ܶࡣ��ҵ�ķ�չ�����˸߲��ķ��١�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west"  : __DIR__"xijie2",
        "east"  : __DIR__"dongjie",
        "south" : __DIR__"nanjie",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


