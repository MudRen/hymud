//Writen by lnwm
//nongjia2.c

inherit ROOM;

void create()
{
    set("short", "农家");
    set("long", @LONG
这是一家简陋的农居，房子用木头做四壁，用茅草搭的顶棚。屋内十
分凌乱。墙壁上唯一的一扇窗户还北一块木板挡上，所以屋里光线十分不
好。你睁大了眼睛才能看清楚屋内的陈设，屋里好象没有人。
LONG
    );
    set("exits", ([
        "east"      :    __DIR__ "lroad4",
        ]));
   
    setup();
}


