// nvren.c     Ů����
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "Ů����", ({ "nv ren", "ren"  }) );
    set( "gender", "Ů��" );
    set( "age", 38 );                
    set( "long", @LONG
�����ˡ���
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //�ֲ���
}

