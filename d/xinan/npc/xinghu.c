// Npc: xinghu.c
//by trill 02/04/97

inherit NPC;



void create()
{

    set_name( "邢虎", ({"xing hu", "robber"}) );
    set("long", @LONG
一个中年汉子，样子较为猥琐，身材不高，一头乱发，身上的衣服破旧
脏乱。
LONG
    );
    set( "gender", "男性" );
    set( "attitude", "heroism" );

    set( "age", 24 );
    set( "qi",1000 );
    set( "max_kee", 500 );
    set( "eff_kee", 500 );
    set( "jing",500 );
    set( "max_sen", 500 );
    set( "eff_sen", 500 );
    set( "combat_exp", 80000 );

    set_skill( "unarmed",250 );


    setup();
    carry_object( "/clone/misc/cloth")->wear();
}

