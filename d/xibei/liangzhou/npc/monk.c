// Npc : monk.c
// hydra
inherit NPC;

void create()
{
    set_name( "����", ({ "he shang", "monk" }) );
    set("title","������");
    set( "attribute", "friendly" );
    set( "gender", "����" );
    set( "age", 27 );
    set( "long", @LONG
�����µ�һ�����У����ڴ����ĳ���
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
        
    setup();
    carry_object("/clone/misc/cloth" )->wear();
}


