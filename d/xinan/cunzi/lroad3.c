//Writen by lnwm
//lroad3.c

inherit ROOM;

void create()
{
    set("short", "小泥路");
    set("long", @LONG
村中的小路，因为村子依山而建，所以道路并不平整，时而高时而低
但这里绿树成茵，许多不知名的小鸟在树梢上叽叽喳喳地叫着。你不觉心
情也宽松了起来，脚步也轻快了。这条路的尽头是一家农舍，远远看去好
象关着门。西南是一个小菜园，也不知是谁家的.
LONG
        );
    set("outdoors","lnwm");
    set("exits", ([
        "southeast"     :       __DIR__ "lroad2",
        "northwest"     :       __DIR__ "chaimen",
        "southwest"     :       __DIR__ "caiyuan2",              
                ]));
    
    setup();
    replace_program(ROOM);
}


