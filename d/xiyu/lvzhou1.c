/* lvzhou1.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */
 
#include <ansi.h> 

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
һ����С�ĺ�����ˮ��ƽ���羵���峺���ף������ں���Ҳȫ��ˮĭ��ȫ��
�����Ĳ���������ȫ�ǲ��������ں�ˮ�������淢�Ե����ޣ���ˮ��ӳ������
���ޱȵĴ�������ɫ��������ɳĮ��Եһ�鲻С�����ޣ����ڵ��ƽϵͣ���ɽ
��ѩˮ�ڻ�����СϪһֱ������������߾��ǻ����Ĵ�Į�ˡ�
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "west" : __DIR__"lvzhou2",
        "east" : "/d/xibei/desert/shamo9",
    ]) );
    set( "outdoors","xiyu");
    setup();
}

void init()
{
    object me=this_player();
    me->set( "hydra/desert/from","����" );
    if ( me->query_temp_marks("is_riding") == "ֻҰ����" )
    {
        write( MAG"Ұ���ռ����߳���ɳĮ������������ڵ��ϣ�һת����ʧããɳĮ�С�\n"NOR);
        me->delete_temp_marks("is_riding");
    }    
}

