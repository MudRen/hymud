// afanti.c     ������
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "������", ({ "a fanti", "fanti"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 40 );                
    set( "long", @LONG
�����ˡ���
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

