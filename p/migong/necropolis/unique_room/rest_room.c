
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", HIB"����"NOR);
        set("long", @LONG
����
LONG);
        
        set("maze", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("no_clean_up", 1);
        set("outdoors", "necropolis");
        
        set("objects",([
                "/p/migong/necropolis/obj/coffin2":1,
        ]));
        setup();
        // replace_program(ROOM);
}
