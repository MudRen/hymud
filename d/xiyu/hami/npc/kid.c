// kid.c    小孩
// Ffox 98-4-30 14:14
inherit NPC;

void create()
{
    set_name( "小孩", ({ "xiao hai", "xiaohai", "hai", "kid"  }) );
    set( "gender", "男性" );                //性别：男
    set( "age", 9 );                
    set( "long", @LONG
本地人……艺人………
LONG );
    set( "attitude", "friendly" );
    set( "inquiry", ([
    "此地" : "不知道……………",
]) );
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

