
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIY"���鷨��"NOR);
        set("long", @LONG
���鷨��
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
        
        set("objects",([
                "/p/migong/necropolis/npc/skeleton_lich_special": 1,  
                "/p/migong/necropolis/npc/zombie_lord_special": 1,  
                "/p/migong/necropolis/npc/ghost_devil_special": 1,  
        ]));
        setup();
        // replace_program(ROOM);
}
