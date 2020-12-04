/* shamo10.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 */

#define DIR   __DIR__"shamo7"
//define the correct way

#include <command.h>
#include "shamo.h"
#include "driftsand.h"

mapping *exit = ({
    ([ "forward" : __FILE__,
         "right" : __FILE__,
         "backward":__DIR__"shamo7",
         "left" : __FILE__,
       ]),
    ([ "right" : __FILE__,
         "backward" : __FILE__,
         "left":__DIR__"shamo7",
         "forward" : __FILE__,
       ]),
    ([ "backward" : __FILE__,
         "left" : __FILE__,
         "forward":__DIR__"shamo7",
         "right": __FILE__,
       ]),
    ([ "left" : __FILE__,
         "forward" : __FILE__,
         "right":__DIR__"shamo7",
         "backward" : __FILE__,
       ]),
});

void create()
{
    set( "short","��ɳĮ" );
    SetLong();

    set( "exits",exit[random( 4 )] );

    set( "outdoors","desert");
    set( "not_startroom",1 );
    set( "�ų�",1 );
    setup();
}

void init()
{
    add_action( "do_look",({ "look","l" }) );
    add_action( "do_jump","jump" );
    add_action( "ActionDrop","drop" );
    call_out( "eventFall",1,this_player() );
    eventClear( environment( this_player() ) );
    SetLong();
}


