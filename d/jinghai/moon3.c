// Room: /d/jinghai/moon3.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
来到了一片茂密的树林里，一棵棵大树笔直的树立着指向云
霄，树冠茂盛葱郁，遮天闭日, 挡住了阳光，显的林中光线昏暗
。不时，有小鸟惊飞而去。向东有一条通往山冈的陡峭小路，伸
延至这里，转而向南逐渐开阔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"moon2",
  "south" : __DIR__"moon4",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
