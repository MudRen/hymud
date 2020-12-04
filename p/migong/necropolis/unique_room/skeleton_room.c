
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIW"¿Ý¹Ç¿Ó"NOR);
        set("long", @LONG
¿Ý¹Ç¿Ó£¡
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
        
        set("objects",([
                "/p/migong/necropolis/npc/skeleton": 5,   
	        "/p/migong/necropolis/npc/skeleton_fighter": 2,    
	        "/p/migong/necropolis/npc/skeleton_mage": 2,  
	        "/p/migong/necropolis/npc/skeleton_lich": 1, 
        ]));
        setup();
        // replace_program(ROOM);
}
