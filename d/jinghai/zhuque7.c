// Room: /d/jinghai/zhuque7.c

inherit ROOM;

void create()
{
	set("short", "西厢房");
	set("long", @LONG
这是客厅旁的厢房，屋角摆放着一张小茶几。垂帘，桐木床
，此外没有别的什么家什了。虽然很简朴但打扫的一尘不染。一
个身着湖绿色长裙的侍女正在擦试茶具，看到你进来慌忙害羞的
低下了头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhuque9",
  "northeast" : __DIR__"zhuque6",
]));
        set("objects",([
       __DIR__"npc/shinv1.c" : 1,
]));


	setup();
	replace_program(ROOM);
}
