 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "回春阁后房");
        set("long", @LONG
掀起一道薄薄的竹帘，就到了后房。屋子里的陈设很简朴，除了一张竹榻和一
个竹椅外就都是书了，四壁都是书架，竟也是竹子做的。书架上堆满了自五代十国
以来的药经，药典，《医宗金鉴》，《黄帝内经》、《神农本草经》、《伤寒论》、
《金匮要略》，应有尽有。
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"chunliuju1",
        ]));
        set("objects", ([
        "/d/huanghe/yyd/npc/gaiyiming":1,
        ]) ); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
