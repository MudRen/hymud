// yizhan.c   驿站
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "驿站");
    set( "long", @LONG
这里是供行人放置寄存马匹的地方，属于官方机构。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shiban01",
]) );
    set( "objects", ([
    __DIR__"npc/yizhang" : 1,
]) );
    setup();
}

