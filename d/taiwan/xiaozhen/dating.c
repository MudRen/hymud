// Room: /d/taiwan/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是一个十分大的厅堂,两排红木椅子在厅中一溜排开,正中的一张太 
师椅上还铺着锦缎.大厅中一片狼藉,除了摔破的碗,杯外,居然还有许多森 
森白骨和骷髅.正中的墙上挂着一副猛虎图. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"huilang",
]));
	set("item_desc", ([ /* sizeof() == 3 */
  "猛虎图" : "这是一幅猛虎下山图,一笔一划,莫不费尽心力.
",
  "图" : "这是一幅猛虎下山图,一笔一划,莫不费尽心力.
",
  "map" : "这是一幅猛虎下山图,一笔一划,莫不费尽心力.
",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/zongwangshi.c" : 1,
  __DIR__"obj/chair.c" : 1,
  __DIR__"obj/powan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
