#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",HIY"»¢É½"NOR);
        set("long",@LONG
ºÃ¶à»¢°¡£¡
LONG);
        set("maze", 1);
        set("no_clean_up", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("outdoors", "forest");  
        set("objects",([
                "/p/migong/shilian/npc/tiger_king": 1,   
                "/p/migong/shilian/npc/tiger_big": 5, 
                "/p/migong/shilian/npc/tiger_baby": 5,   
                "/p/migong/shilian/obj/box1": 1,       
        ]));
        setup();
}