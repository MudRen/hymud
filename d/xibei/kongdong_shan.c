inherit ROOM;
void create()
{
    set("short","崆峒山脚");
    set("long",@LONG
崆峒山以西晋时广成子在此修炼成仙而闻名。山上有许多真人胜迹，飞崖险
涧，是个游览的好去处。
LONG);
    set("exits",([
        "south"  : __DIR__"shanlu1",
        "north" : __DIR__"kongdong/fengkou",
    ]));
set("outdoors","xibei");
    setup();
}

