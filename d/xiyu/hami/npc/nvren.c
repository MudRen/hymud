// nvren.c     女主人
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "女主人", ({ "nv ren", "ren"  }) );
    set( "gender", "女性" );
    set( "age", 38 );                
    set( "long", @LONG
本地人……
LONG );
    set( "attitude", "friendly" );

    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

