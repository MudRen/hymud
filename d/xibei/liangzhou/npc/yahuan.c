// Npc : yuhuan.c  Ѿ��
// hydra
inherit NPC;

void create()
{
    set_name( "Ѿ��", ({ "ya huan", "yahuan" }) );
    set( "title","�Ÿ�" );
    set( "attribute", "friendly" );
    set( "gender", "Ů��" );
    set( "age", 18 );
    set( "long", @LONG
����С���Ѿ��
LONG
    );
    
    set( "per",30 );
    set( "int",26 );
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
    
}


