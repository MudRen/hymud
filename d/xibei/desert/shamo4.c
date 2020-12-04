/* shamo4.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980328
 */

#define DIR   __DIR__"shamo8"
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : __DIR__"shamo8",
         "right" : __DIR__"shamo" + random( 5 ),
         "backward":__DIR__"shamo5",
         "left" : __DIR__"shamo" + random( 5 ),
       ]),
    ([ "right" : __DIR__"shamo8",
         "backward" : __DIR__"shamo" + random( 5 ),
         "left":__DIR__"shamo5",
         "forward" : __DIR__"shamo" + random( 5 ),
       ]),
    ([ "backward" : __DIR__"shamo8",
         "left" : __DIR__"shamo" + random( 5 ),
         "forward":__DIR__"shamo5",
         "right": __DIR__"shamo" + random( 5 ),
       ]),
    ([ "left" : __DIR__"shamo8",
         "forward" : __DIR__"shamo" + random( 5 ),
         "right":__DIR__"shamo5",
         "backward" : __DIR__"shamo" + random( 5 ),
       ]),
});


void create()
{
    set( "short","��ɳĮ" );
    SetLong();

    set( "exits",exit[random( 4 )] );
    if ( random( 3 ) == 0 )
        set( "objects",([
            __DIR__"npc/lingyang":1,
        ]) );

    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 2 )
        new( __DIR__"obj/xiaostone" ) -> move( this_object() );
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    SetLong();
    remove_call_out("greet_me");
    call_out("greet_me",1,this_player());
}

