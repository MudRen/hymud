// yizhang.c     �䳤
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "�䳤", ({ "yi zhang", "yizhang", "zhang"  }) );
    set( "gender", "����" );                //�Ա���
    set( "age", 35 );                
    set( "long", @LONG
�����ˡ������ˡ�����
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

