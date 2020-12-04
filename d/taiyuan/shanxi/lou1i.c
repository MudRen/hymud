inherit ROOM;
#include <room.h>
#include <ansi.h>
void create() 
{ 
    set("short", WHT"隔岸观火"NOR); 
    set("long", @long
诳也，非诳也，实其所诳也。少阴、太阴、太阳。示之以动，
利其静而有主，“益动而巽”。阳乖序乱，明以待逆。暴戾恣睢，
其势自毙。顺以动豫，豫顺以动。
long 
    ); 
    set("exits", ([ 
    	"up" : __DIR__"lou2a", 
    	"north" : __DIR__"lou1h",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                __DIR__"npc/duo": 1,
                
        ]));
        
        set("no_magic",1);
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
                //create_door("out", "石门", "enter", DOOR_CLOSED); 

} 