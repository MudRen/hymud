#include <room.h>
#include <ansi.h>
inherit ROOM; 

void create() 
{ 
	set("short", "С·");
	set("long", @LONG
������һ��С·�ϡ�ǰ���·��᫣����˺��١�
LONG );
                        
        set("outdoors", "forest"); 
        set("no_magic",1);
  set("magicroom",1);
set("magicset",1);
set("no_npc",1);
set("no_fight",1);
set("sleep_room",1);
     
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"VRM_00122/exit",
                "south":__DIR__"VRM_00123/entry",
        ])); 
                        
        setup();
        // replace_program(ROOM); 
} 



