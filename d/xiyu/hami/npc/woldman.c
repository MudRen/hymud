
#include <ansi.h>

inherit NPC;

void create()
{
    set_name( "��������", ({ "hami laoren", "laoren"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 60 );                
    set( "long", @LONG
���ص�һ�����ˣ�����ȥ�Ǻ����е����ӣ�һ�����ڽֵ���ת��
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

