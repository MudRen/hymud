/* yumenguan.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */

inherit ROOM;

void create()
{
    set( "short","���Ź���" );
    set( "long",@LONG
���Ź�������ͨ����ԭ��һ����Ҫ�ؿ�����������������ǿ�ң���Χ��
����ɳĮ����ڣ���ݲ���������֮����ʫ�ơ�Ǽ�Ѻ���ԩ���������粻������
�ء���̧ͷ��������ǰ�����޲ݣ�ֻ�����ɫ��ʯ�ӵ������������棻��ڡ�ɳ
Į������������������������һ�����þ���
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : "/d/xibei/desert/shamo0",
        "southeast" : __DIR__"dunhuang",
    ]) );
    set( "outdoors","silk");
    setup();
}

void init()
{
    this_player() -> set( "hydra/desert/from","��ԭ" );
}

