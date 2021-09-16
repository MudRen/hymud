// yizhan.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "驿站");
	set("long", @LONG
这是里的一间非常寻常驿站，专为朝廷接送官员，传递公文
之用；如果没有公务，偶而也会出租驿马或为过往客商提供食宿。
外面就是侯集镇街道。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"shilu6",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
