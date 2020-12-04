//Writen by lnwm
//lroad2.c

inherit ROOM;

void create()
{
    set("short", "小泥路");
    set("long", @LONG
你穿过树林，来到了一个小村子，这是四川山区最常见的小村子，紧
挨着青城山的后山。偏僻而幽静。往东是一片竹林，西边是青城山的后山
往西有一条小路，通向一个农家。
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "south"         :       __DIR__ "lroad1",
        "northwest"     :       __DIR__ "lroad3",
        "north"         :       __DIR__ "lroad4",    
        "northeast"     :       __DIR__ "zhulin",              
                ]));
    set("objects",([
                __DIR__ "npc/girl" : 1,
                  ])                  
    );
    setup();
    replace_program(ROOM);
}


