#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIR"ÁúÑ¨"NOR);
        set("long",@LONG
ºÃ¶àÁú°¡£¡
LONG);

        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");
        
        set("objects",([
                "/p/migong/forest/npc/dragon": 1,  
                "/p/migong/forest/npc/dragon_baby": 5,    
                "/p/migong/forest/obj/box2": 1, 
        ]));        
        setup();
}