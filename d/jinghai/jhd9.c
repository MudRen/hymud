// Room: /d/jinghai/jhd9.c

inherit ROOM;

void create()
{
	set("short", "靖海公府邸正门");
	set("long", @LONG
这里是靖海公府的正门，漆黑的大门左右敞开，门上方横着
一块黑底金字的横匾，上书 靖海公府 四个恭楷大字，据说这是
邓璨亲手提写的，字迹虽不十分优美，但一钩一划却是箭拔弩张
，气像森严，由此可以看出书写之人必是一位胸有甲兵的豪杰之
士。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jhd8",
  "west" : __DIR__"jhd10",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
