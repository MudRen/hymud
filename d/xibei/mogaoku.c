/* mogaoku.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","Ī�߿�" );
    set( "long",@LONG
������λ�ڶػͶ��ϵ�Ī�߿ߣ������Ƿ���Ĺ��ڣ������ĵ��á���һ����
�������Щ�������������ݴ���Ĵ���������·����΢Ц��ӭ����Ŀ��
���Ľ�ա���ʿ��������������η�������ıڡ��߶������������Ƿ����Լ���
�졢��Ů�����б�ó���Ĺ��ޡ�ÿһ��������չʾ������һ�������Ĺ��¡�
LONG
    );

    set( "exits",([ /* sizeof() ==1 */
        "northwest" : __DIR__"dunhuang",
    ]) );
    set( "outdoors","silk");
    setup();
}


