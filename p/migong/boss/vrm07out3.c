#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", "小路");
	set("long", @LONG
你走在一条小路上。前面道路崎岖，行人很少。
LONG );
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
     
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"VRM_00073/exit",
                "south":__DIR__"VRM_0007/entry",
        ])); 
                        
        setup();
        // replace_program(ROOM); 
} 



