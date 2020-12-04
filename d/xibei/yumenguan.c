/* yumenguan.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980407
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980407
 */
#include <ansi.h>
inherit ROOM;

void CloneCorpse();

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
        "west" : __DIR__"desert/shamo0",
        "southeast" : __DIR__"dunhuang",
        "south"  : "/d/qilian/yumenguan",	
    ]) );
    set( "outdoors","silk");
    setup();
}

void init()
{
    object me = this_player();
    me -> set( "hydra/desert/from","��ԭ" );
    if ( !random(5) )
    {
        CloneCorpse();
    }
    if ( me->query_temp_marks("is_riding") == "ֻҰ����" )
    {
        write( MAG"Ұ���ռ����߳���ɳĮ������������ڵ��ϣ�һת����ʧããɳĮ�С�\n"NOR);
        me->delete_temp_marks("is_riding");
    }
}

void CloneCorpse()
{
    object ob,corpse;
    ob = new(__DIR__"npc/compass");
    corpse = new("/clone/misc/corpse");
    corpse ->set("name","�ɿݵ�ʬ��");
    corpse ->set("long",@LONG
һ�߸ɿݵ�ʬ�壬��Ȼ����ɳĮ��ˮ�����Ĺ⣬�ò�������������
ɳĮ��ȱ�������ˡ�
LONG
    );
    corpse->set_max_encumbrance( 1000 );
    corpse->move(this_object());
    ob->move(corpse);
}
