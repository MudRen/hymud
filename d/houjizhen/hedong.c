// hezhong.c
// by dicky

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "水底洞穴");
    set("long", @LONG
你屏气凝神，进入水底洞穴。这里没有太多的光线，只能模模糊糊
的看到一些东西。突然，一庞然大物向你扑过来，你忙运功抵抗这突来
的遭遇，心中不免有些紧张。
LONG
        );

	set("outdoors", "houjizhen");

	set("exits", ([
		"out" :  __DIR__"hedi",
	]));

        set("objects",([
		__DIR__"npc/eyu" : 1,
	]));

	set("outdoors", "houjizhen");
	setup();
}