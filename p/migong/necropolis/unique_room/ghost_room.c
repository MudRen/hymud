
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIM "��������" NOR);
        set("long", @LONG
�������ã�
LONG);
        
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "necropolis");
        
        set("objects",([
	        "/p/migong/necropolis/npc/ghost": 5,   
	        "/p/migong/necropolis/npc/ghost_fire": 2,    
	        "/p/migong/necropolis/npc/ghost_eye": 2,  
                "/p/migong/necropolis/npc/ghost_devil": 1,  
        ]));
        setup();
        // replace_program(ROOM);
}
