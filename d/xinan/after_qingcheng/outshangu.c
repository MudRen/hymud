//writen by lnwm
//outshangu.c

inherit ROOM;
void create()
{
    set("short", "四川西北山区");
    set("long", @LONG
四川西北的崇山峻岭之中.四周的山高高低低,有的奇峰突起.有的畹转低回.
满山具是草木葱盛,满眼都是无边的绿色.偶尔有山涧从旁侧的山谷中蜿蜒而出
水声潺潺从你脚下流过,然后悄悄隐入无边的绿色之中.你在水光山色中迤逦而
行.
LONG
        );
    set("exits", ([ 
		"east"      :       __DIR__ "shangu8",
	    "west"      :       __DIR__ "gudi",
    ]));
    set("outdoors","lnwm");
    setup();
}
