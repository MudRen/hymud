/* shanjiao.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","��ɽ����" );
    set( "long",@LONG
���಻������ɽ���������ǰ��Զ����ɽ���������ˣ��ǳ����ѩ�߲�����
���Ʒ壬����Ůͷ�ϵ���ڣ������������Ǹ���ɫ�ʵĲ��ϵ�ɽ�ͣ����ȸ����
�������������ˡ���ɽ�з��ĵ�ˮ�ݣ����̷��Ƶ�ɭ�֣������겻���Ļ�ѩ����
Ȼ���и�������ҩ�ġ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "east" : __DIR__"muchang",
    "southwest" : "/d/xingxiu/shanjiao",	
    ]) );
    set( "outdoors","xiyu");
    setup();
}


