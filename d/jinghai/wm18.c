// Room: /d/jinghai/wm18.c

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这里是一片黑暗，伸手不见五指。四处都是死气沉沉地毫无
声息，越发显得阴森恐怖。突然间一阵冷风迎面吹来，带来一股
扑鼻的霉气。什么都看不到，什么也听不到。空气中有一股腐烂
的味道。渐渐的，你感到呼吸困难起来，看来这里并不透风。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"wm14",
]));

	
	set("objects",([
	__DIR__"npc/lao_kanshou" : 1,
]));

	setup();
	replace_program(ROOM);
}
