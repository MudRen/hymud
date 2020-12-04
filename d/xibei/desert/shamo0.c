/* shamo0.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980325
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980328
 */

#define DIR   __DIR__"shamo1" 
//define the correct way

#include "shamo.h"

mapping *exit = ({
    ([ "forward" : __DIR__"shamo1" ,
         "right" : __DIR__"shamo" + random( 5 ) ,
         "backward":"/d/xibei/yumenguan" ,
         "left" : __DIR__"shamo" + random( 5 ) ,
       ]),
    ([ "right" : __DIR__"shamo1" ,
         "backward" : __DIR__"shamo" + random( 5 ),
         "left":"/d/xibei/yumenguan",
         "forward" : __DIR__"shamo" + random( 5 ),
       ]),
    ([ "backward" : __DIR__"shamo1",
         "left" : __DIR__"shamo" + random( 5 ),
         "forward":"/d/xibei/yumenguan",
         "right": __DIR__"shamo" + random( 5 ),
       ]),
    ([ "left" : __DIR__"shamo1",
         "forward" : __DIR__"shamo" + random( 5 ),
         "right":"/d/xibei/yumenguan",
         "backward" : __DIR__"shamo" + random( 5 ),
       ]),
});

void SetLong();

void create()
{
    set( "short","��ɳĮ" );
    SetLong();

    set( "not_startroom",1 );
    set( "outdoors","desert");
    setup();
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 1 )
        new( __DIR__"obj/stone" ) -> move( this_object() );
    if( random( 4 ) == 2 )
        new( __DIR__"obj/xiaostone" ) -> move( this_object() );
    set( "exits",exit[random( 4 )] );  
}

void init()
{
    SetLong();
    add_action( "do_look",({ "look","l" }) );
    if( this_player()->query( "hydra/desert/from" ) == "��ԭ" )
        call_out( "DecWater",60,this_player(),time() );
}


