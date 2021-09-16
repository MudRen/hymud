// Room: /d/jinghai/jhd8.c

inherit ROOM;

void create()
{
	set("short", "门前空地");
	set("long", @LONG
这是一片青石铺成的小院落。之所以叫它院落是因为它三面
被巨大的红杉所包围，东面有一条小路蜿蜒地没入错综交杂的板
状根中，而唯一没有被红杉占据的西面就是靖海公府的府邸所在
之地了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"jhd7",
  "west" : __DIR__"jhd9",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
