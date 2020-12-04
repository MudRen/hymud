/* shamo1.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980328
 */

#define DIR   __DIR__"shamo2"
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : __DIR__"shamo2",
         "right" : __DIR__"shamo" + random( 5 ),
         "backward":__DIR__"shamo0",
         "left" : __DIR__"shamo" + random( 5 ),
       ]),
    ([ "right" : __DIR__"shamo2",
         "backward" : __DIR__"shamo" + random( 5 ),
         "left":__DIR__"shamo0",
         "forward" : __DIR__"shamo" + random( 5 ),
       ]),
    ([ "backward" : __DIR__"shamo2",
         "left" : __DIR__"shamo" + random( 5 ),
         "forward":__DIR__"shamo0",
         "right": __DIR__"shamo" + random( 5 ),
       ]),
    ([ "left" : __DIR__"shamo2",
         "forward" : __DIR__"shamo" + random( 5 ),
         "right":__DIR__"shamo0",
         "backward" : __DIR__"shamo" + random( 5 ),
       ]),
});
void eventClear( object );

void create()
{
    set( "short","��ɳĮ" );
    SetLong();
       
    set( "exits",exit[ random( 4 ) ] );
    if ( random( 3 ) == 0 )
        set( "objects",([ /*sizeof() == 1*/
            __DIR__"npc/camel":1,
        ]) );
    set( "outdoors","desert");
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    eventClear( this_object() );
    SetLong();
}


