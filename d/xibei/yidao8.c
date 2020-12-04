inherit ROOM;
void create()
{
    set("short","驿道");
    set("long",@LONG
西行逼近边境，驻军渐多；向西，北望去，田野之中军寨，城堡星罗棋布，
不时有一队队官军沿着田陇巡逻。这一带大城镇渐少，只在军堡之间夹着许多农
田，一些小田庄分散其间。每个军寨四周还有官军开垦的军屯。南面是一片高山
险岭。
LONG);
    set("exits",([
        "east"   : __DIR__"yidao7",
        "west"  : __DIR__"yidao9",
    ]));
 set("outdoors","xibei");
    setup();
}

