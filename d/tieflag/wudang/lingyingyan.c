 inherit ROOM;
void create()
{
        set("short", "灵应岩");
        set("long", @LONG
五龙宫背靠的山峰叫“大五龙灵应万寿峰”，俗称“五龙顶”。
它在每年的多数日子里都是云雾繚绕，给人以高不可测的感觉。
LONG
        );
        set("exits", ([
                "south" : __DIR__"wuroad3",
        ]));
        set("outdoors", "wudangfy");
        set("objects", ([
                __DIR__"npc/taoist4" : 1,
                __DIR__"npc/taoist_1" : 1,
        ]));
        set("coor/x",130);
        set("coor/y",-120);
        set("coor/z",50);
        setup();
        replace_program(ROOM);
}   
