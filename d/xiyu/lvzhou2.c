/* lvzhou2.c
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
һ����С�ĺ�����ˮ��ƽ���羵���峺���ף������ں���Ҳȫ��ˮĭ��ȫ��
�����Ĳ���������ȫ�ǲ��������ں�ˮ�������淢�Ե����ޣ���ˮ��ӳ������
���ޱȵĴ�������ɫ��������ɳĮ��Եһ�鲻С�����ޣ����ڵ��ƽϵͣ���ɽ
��ѩˮ�ڻ�����СϪһֱ�������
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "northwest" : __DIR__"yanqi",
        "east" : __DIR__"lvzhou1",
    ]) );
    set( "outdoors","xiyu");
    setup();
}


